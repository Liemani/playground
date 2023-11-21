import pandas as pd

df_org = pd.read_csv("./data/df_new.csv")

pos_reviews = df_org[df_org["label"] == 1]
neg_reviews = df_org[df_org["label"] == 0]

import re
pos_reviews.loc[ : , "comment"] = [re.sub(r"[^ㄱ-ㅣ가-힣]", " ", data) for data in pos_reviews["comment"]]
neg_reviews.loc[ : , "comment"] = [re.sub(r"[^ㄱ-ㅣ가-힣]", " ", data) for data in neg_reviews["comment"]]

import jpype
from konlpy.tag import Okt

okt = Okt()
okt

print(pos_reviews["comment"][1])
okt.nouns(pos_reviews["comment"][1])
len(pos_reviews["comment"])

#     print(cmt)
#     print(okt.nouns(cmt))
pos_comment_nouns = []
for cmt in pos_reviews["comment"] :
    pos_comment_nouns.extend(okt.nouns(cmt))
print(len(pos_comment_nouns), " \n", pos_comment_nouns)

neg_comment_nouns = []
for cmt in neg_reviews["comment"] :
    neg_comment_nouns.extend(okt.nouns(cmt))

pos_comment_nouns2 = [w for w in pos_comment_nouns if len(w) > 1]
print(len(pos_comment_nouns2), pos_comment_nouns2)

neg_comment_nouns2 = [w for w in neg_comment_nouns if len(w) > 1]
print(len(neg_comment_nouns2), neg_comment_nouns2)

# 빈도분석 start
from collections import Counter
pos_word_count = Counter(pos_comment_nouns2)
neg_word_count = Counter(neg_comment_nouns2)

pos_top_20 = {}
for word, counts in pos_word_count.most_common(20) :
    pos_top_20[word] = counts

neg_top_20 = {}
for word, counts in neg_word_count.most_common(20) :
    neg_top_20[word] = counts
# 빈도분석 end

# visualize start
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

plt.rc("font", family="AppleGothic")
plt.rcParams["axes.unicode_minus"] = False

plt.figure(figsize=(10, 5))
plt.title("pos/neg word top 20 counts", fontsize="17")

for key, value in neg_top_20.items() :
    if key == "영화" :
        continue
    plt.bar(key, value, color="lightgrey")

plt.xlabel("word")
plt.ylabel("counts")
plt.show()
# visualize end

# visualize with wordcloud start
from wordcloud import WordCloud

plt.figure(figsize = (8, 8))
plt.title("긍정 리뷰에 대한 상위 단어 20개 클라우드")

font_path = "/Library/Fonts/AppleGothic.ttf"

wc = WordCloud(
    font_path = font_path,
    background_color = "ivory",
    width = 800,
    height = 600)

cloud = wc.generate_from_frequencies(pos_top_20)

plt.imshow(cloud)

plt.axis("off")

plt.show()
# visualize with wordcloud end

# neg visualize with wordcloud start
from wordcloud import WordCloud

plt.figure(figsize = (8, 8))
plt.title("긍정 리뷰에 대한 상위 단어 20개 클라우드")

font_path = "/Library/Fonts/AppleGothic.ttf"

wc = WordCloud(
    font_path = font_path,
    background_color = "black",
    width = 800,
    height = 600)

cloud = wc.generate_from_frequencies(neg_top_20)

plt.imshow(cloud)

plt.axis("off")

plt.show()
# neg visualize with wordcloud end
