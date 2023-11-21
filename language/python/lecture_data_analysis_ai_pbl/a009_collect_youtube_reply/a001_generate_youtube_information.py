"""
- get youtube api certificate key
- collect information of youtube channel
- video download
- collect video reply
"""

"""
google cloud platform
youtube api key
- youtube data api v3
"""

"""
channel url : https://www.youtube.com/@tank_man1536
channel id  : UCsN3Otim4Fu7ahQhJugHqbg
- view page source > find externalId value
"""

from googleapiclient.discovery import build
from googleapiclient.errors import HttpError
import conf

# check video count start
youtube = build("youtube", "v3", developerKey = conf.YOUTUBE_API_KEY)
try :
    channel_response = youtube.channels().list(
        part = "statistics",
        id = conf.CHANNEL_ID
    ).execute()
    print("[동영상 목록] \n", channel_response)
    video_count = int(channel_response["items"][0]["statistics"]["videoCount"])
    print("[전체 동영상 갯수] : ", video_count)
except HttpError as e :
    print("[에러 발생] : ", e)
# check video count end

# my youtube channel start
try :
    response = youtube.channels().list(
        part = "statistics",
        id = "UC1JLSDpr2x73y8SH6_1N3EQ"
    ).execute()
except HttpError as e :
    print("[에러 발생] : ", e)
# my youtube channel end

def videoCount(response) :
    return int(response["items"][0]["statistics"]["videoCount"])

# get channel datum start
try :
    request = youtube.search().list(
        part = "id, snippet",
        channelId = conf.CHANNEL_ID,
        order = "date",
        type = "video",
        maxResults = 2,
    )
    response = request.execute()
    for item in response["items"] :
        video_id =  item["id"]["videoId"]
        video_title = item["snippet"]["title"]
        print(f"동영상 ID : {video_id} / 동영상 제목 : {video_title}")
except HttpError as e :
    print(f"An HTTP Error {e.resp.status} occurred :\n {e.content}")
# get channel datum end

def savePrettyPrintToTemp(jsonDictionary) :
    json_object = json.dumps(jsonDictionary, indent = 4)
    with open('.temp', 'w') as f:
        print(json_object, file = f)

# check channel change start
import time

try :
    channel_response = youtube.channels().list(
        part = "statistics",
        id = conf.CHANNEL_ID
    ).execute()
    video_count = int(channel_response["items"][0]["statistics"]["videoCount"])
    beforeCount = video_count
except HttpError as e :
    print("[에러 발생] : ", e)

print ("beforeCount : ", beforeCount)

cnt = 1
while True :
    if cnt >= 11 :
        break
    try :
        channel_response = youtube.channels().list(
            part = "statistics",
            id = conf.CHANNEL_ID
        ).execute()
        video_count = int(channel_response["items"][0]["statistics"]["videoCount"])
        afterCount = video_count
        print("------------------------------")
    except HttpError as e :
        print("[에러 발생] : ", e)
    result = afterCount - beforeCount
    if result :
        print(f"동영상 갯수에 변경이 있습니다. : before{beforeCount} / after{afterCount} / add{result}")
    else :
        print(f"동영상 갯수에 변경이 없습니다. : before{beforeCount} / after{afterCount} / add{result}")
    print("==============================\n")
    beforeCount = afterCount
    time.sleep(3)
    cnt += 1
# check channel change end

# check channel update with search().list() start
beforeVideos = []
try :
    request = youtube.search().list(
        part = "id, snippet",
        channelId = conf.CHANNEL_ID,
        order = "date",
        type = "video",
        maxResults = 2,
    )
    response = request.execute()
    for item in response["items"] :
        video_id =  item["id"]["videoId"]
        video_title = item["snippet"]["title"]
        print(f"동영상 ID : {video_id} / 동영상 제목 : {video_title}")
        beforeVideos.append(video_title)
    beforeSet = set(beforeVideos)
    print(f"[beforeSet정보] : {beforeSet}")
except HttpError as e :
    print(f"An HTTP Error {e.resp.status} occurred :\n {e.content}")
# check channel update with search().list() end

# check channel update with search().list() start
cnt = 1
afterVideos = []
while True :
    if cnt >= 6 :
        break
    try :
        request = youtube.search().list(
            part = "id, snippet",
            channelId = conf.CHANNEL_ID,
            order = "date",
            type = "video",
            maxResults = 3,
        )
        response = request.execute()
        for item in response["items"] :
            video_id =  item["id"]["videoId"]
            video_title = item["snippet"]["title"]
            print(f"동영상 ID : {video_id} / 동영상 제목 : {video_title}")
            afterVideos.append(video_title)
        afterSet = set(afterVideos)
        print(f"[afterSet정보] : {afterSet}")
        print("------------------------------")
    except HttpError as e :
        print(f"An HTTP Error {e.resp.status} occurred :\n {e.content}")
    result = afterSet - beforeSet
    if result :
        print("** 동영상 목록(개수)에 변경이 있습니다. >>>>>")
        print(" * 추가된 영상 제목 : ", result)
    else :
        print("** 동영상 목록(개수)에 변경이 없습니다. >>>>>")
        print(" * 추가된 영상 제목: ", result)
    print("==============================\n")
    beforeSet = afterSet
    time.sleep(3)
    cnt += 1
# check channel update with search().list() end

from pytube import YouTube

def on_progress(vid, chunk, bytes_remaining) :
    total_size = vid.filesize
    bytes_downloaded = total_size - bytes_remaining
    percentage_of_completion = bytes_downloaded / total_size * 100
    percentage_of_completion = round(percentage_of_completion, 2)
    totalsz = (total_size / 1024) / 1024
    totalsz = round(totalsz, 1)
    remain = (bytes_remaining / 1024) / 1024
    remain = round(remain, 1)
    dwnd = (bytes_downloaded / 1024) / 1024
    dwnd = round(dwnd, 1)
    print(f"Download Progress : {percentage_of_completion}%, \
        Total Size : {totalsz}MB, \
        Downloaded : {dwnd}MB, \
        Remaining : {remain}MB")

def download_youtube_720(title, videoId) :
    url = "https://youtu.be/" + videoId
    print(f"제목 : {title} / 주소 : {url} : 영상 다운로드 받기")
    down_path = "./download/"
    YouTube(
        url,
        use_oauth = True,
        allow_oauth_cache = True,
        on_progress_callback = on_progress
    ).streams.filter(res = "720p").first().download(output_path = down_path)

download_youtube_720("Q&amp;A하겠습니다", "qddxyfuT5MQ")
download_youtube_720("제프의 저주에 걸린 탱크맨", "Gkhe71qXyKM")

# collect video reply start
import pandas as pd

video_id = "Gkhe71qXyKM"
request = youtube.commentThreads().list(
    part = "snippet,replies",
    videoId = video_id,
    maxResults = 100,
)
response = request.execute()
print("response 결과 ----------\n", response, "\n ==========\n")

comments = list()
while response :
    for item in response["items"] :
        comment = item["snippet"]["topLevelComment"]["snippet"]
        comments.append([
            comment["textDisplay"],
            comment["authorDisplayName"],
            comment["publishedAt"],
            comment["likeCount"],
        ])
        if item["snippet"]["totalReplyCount"] > 0 :
            for reply_item in item["replies"]["comments"] :
                reply = reply_item["snippet"]
                comments.append([
                    reply["textDisplay"],
                    reply["authorDisplayName"],
                    reply["publishedAt"],
                    reply["likeCount"],
                ])
    if "nextPageToken" in response :
        request = api_obj.commentThreads().list(
            part = "snippet,replies",
            videoId = video_id,
            pageToken = response["nextPageToken"],
            maxResults = 100,
        )
        response = request.execute()
    else :
        break
# collect video reply end

df = pd.DataFrame(comments)
df.columns = ["comment", "author", "date", "num_likes"]
df.to_excel("./data/youtube_results.xlsx")
df.to_csv("./data/youtube_results.csv")
