import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams["axes.unicode_minus"] = False

# import plotly.express as px

import folium
import warnings

warnings.filterwarnings(action = "ignore")

# collect free wifi data
# - 수집 URL : https://www.localdata.go.kr/
#   생활 편의 정보 > 생활 밀착 데이터 > 무료 와이파이 정보
#   서울, 부산, 대전, 세종
df = pd.read_excel("/Users/bagjeonghun/remote/personal/playground/python/lecture_data_analysis_ai_pbl/sj_env_01/day003_visualize_and_free_wifi_search/a002_free_wifi_search/data/org/대전_12_04_07_E_무료와이파이정보.xlsx")
# df = pd.read_excel("./data/org/대전_12_04_07_E_무료와이파이정보.xlsx")

import os

path = "/Users/bagjeonghun/remote/personal/playground/python/lecture_data_analysis_ai_pbl/sj_env_01/day003_visualize_and_free_wifi_search/a002_free_wifi_search/data/org/"
file_list = os.listdir(path)

# 수집한 데이터 통합하기
def read_all_excel(directory) :
    basename_list = os.listdir(path)
    df = pd.DataFrame()
    for basename in basename_list :
        df_temp = pd.read_excel(directory + "/" + basename)
        df = pd.concat([df, df_temp], ignore_index = True)
    return df

df = read_all_excel(path)
df.info()

df["설치시설구분"].unique()

c = df["설치시설구분"].str.contains("서민")
df.loc[c, "설치시설구분"] = "서민복지시설"

print(os.getcwd())

# 대전 : 36.3511, 127.3866
m = folium.Map(location = [36.3511, 127.3866], zoom_start = 14)

m.add_child(folium.ClickForMarker(popup = "point"))
m.add_child(folium.LatLngPopup())

def save_map(map) :
    path = "/Users/bagjeonghun/Downloads/map.html"
    map.save(path)

address = input("도로명 주소를 입력해주세요! : ")

def generate_map(address) :
    coordinate = geocoding(address)
    map = folium.Map(location = [
        coordinate[0],
        coordinate[1]], zoom_start = 14)
    return map

my_home = generate_map(address)

address = input("도로명 주소를 입력해주세요! : ")

from geopy.geocoders import Nominatim

def geocoding(address) :
    geolocoder = Nominatim(user_agent = "South Korea", timeout = 10)
    geo = geolocoder.geocode(address)
    coordinate = (geo.latitude, geo.longitude)
    return coordinate

coordinate = geocoding(address)
print("coordinate --->", coordinate)
print("위도 :", coordinate["latitude"])
print("경도 :", coordinate["longitude"])

folium.Marker(
    [ coordinate[0], coordinate[1] ],
    icon = folium.Icon(
        color="red",
        icon = "glyphicon glyphicon-home")
).add_to(coordinate)

from geopy.distance import geodesic

myhome = (coordinate["latitude"], coordinate["longitude"])

address = "대전 유성구 동서대로 725"
state_name = address.split(" ")[0]

daejeon_dataframe = df.loc[df["설치시도명"].str.contains(state_name)]

my_wifi = pd.DataFrame(columns=["설치시군구명", "설치시설구분", "위도", "경도", "거리"])
for index in daejeon_dataframe.index :
    wifi_loc = (df.loc[index, "WGS84위도"], df.loc[index, "WGS84경도"])
    my_wifi.loc[index] = [
        df.loc[index, "설치시군구명"],
        df.loc[index, "설치시설구분"],
        df.loc[index, "WGS84위도"],
        df.loc[index, "WGS84경도"],
        geodesic(coordinate, wifi_loc).kilometers]

my_wifi = my_wifi.sort_values(by = ["거리"]).head(10)

folium.Marker(
    [ coordinate[0], coordinate[1] ],
    icon = folium.Icon(
        color = "red",
        icon = "glyphicon glyphicon-home")
).add_to(map)

for index in my_wifi.index :
    folium.Marker(
        [ my_wifi.loc[index, "위도"], my_wifi.loc[index, "경도"] ],
        popup = "<pre>" + my_wifi.loc[index, "설치시설구분"] + "</pre>",
        icon = folium.Icon(
            color = "blue",
            icon = "wifi",
            prefix = "fa")
    ).add_to(map)
