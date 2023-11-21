import pandas as pd

df_org = pd.read_csv("./data/movie_reviews.txt", delimiter = "\t",
    names = ["title", "rate", "comment", "label"])
df_org.info()

df = df_org.copy()
df.describe()
c = df["rate"] == 0
df[c]
df["rate"].value_counts()
df[df.duplicated(keep = False) == True]

kdf_del = df_org[df_org.duplicated()]
print(f"원본 전체 건수[{len(df_org)}] / 제거할 중복 건수[{len(df_del)}] / 중복 처리 후 건수[{len(df_org) - len(df_del)}]")

df_new = df_org.drop_duplicates()
print("중복 처리 후 건수 : ", len(df_new))
df_new.head(2)

movie_list = df_new["title"].unique()

movie_cnt = df_new["title"].value_counts()

movie_info = df_new.groupby("title")["rate"].describe()

movie_info.sort_values(by = "count", axis = 0, ascending = False)

import matplotlib.pyplot as plt

from matplotlib import font_manager, rc
plt.rc("font", family = "Malgun Gothic")
plt.rcParams["axes.unicode_minus"] = False

import numpy as np

# 영화 제목만 리스트 타입으로 추출하기
movie_title = df_new["title"].unique().tolist()
movie_title

avg_score = {}
for title in movie_title :
    avg = df_new[df_new["title"] == title]["rate"].mean()
    avg_score[title] = avg

# bar graph start
plt.figure(figsize = (10, 5))
plt.title("movie rate average", fontsize = 17)

### 각 영화별 평점 평균에 대한 막대 그리기
for title, rate in avg_score.items() :
#     color = np.array_str(np.where(y == max(avg_score.values()), "orange", "lightgrey"))
    plt.bar(title, rate, color = "lightgrey")
    plt.text(title, rate, "%.2f"%rate, horizontalalignment = "center", verticalalignment = "bottom")

plt.xlabel("title")
plt.ylabel("rate average")

plt.xticks(rotation = 75)

plt.show()
# bar graph end

# graph start
### subplots(행의 수, 열의 수, 전체 그래프 사이즈)
### 전체 graph 는 fig 가 갖는다
### 작은 graph 는 axs 가 갖는다
fig, axs = plt.subplots(5, 2, figsize = (15, 25))
axs = axs.flatten()
for title, average, ax in zip(avg_score.keys(), avg_score.values(), axs) :
    num_reviews = len(df_new[df_new["title"] == title])
    x = np.arange(num_reviews)
    y = df_new[df_new["title"] == title]["rate"]
    ax.set_title(f"{title} ({num_reviews})", fontsize = 15)
    ax.plot(x, y, "o")
    ax.axhline(average, color="red", linestyle = "--")

plt.show()
# graph end

# pi graph start
fig, axs = plt.subplots(5, 2, figsize = (15, 25))
axs = axs.flatten()

colors = ["pink", "gold", "whitesmoke"]
labels = ["positive(8~10)", "negative(0~4)", "etc(5~7)"]

for title, ax in zip(avg_score.keys(), axs) :
    num_reviews = len(df_new[df_new["title"] == title])
    values = df_new[df_new["title"] == title]["label"].value_counts()
    ax.set_title(f"{title} ({num_reviews})", fontsize = 15)
    ax.pie(
        values,
        labels = labels,
        autopct = "%1.1f%%",
        colors = colors,
        shadow = True,
        startangle = 90)

plt.show()
# pi graph end

# save preprocessed file start
df_new.to_csv("./data/df_new.csv", index = None)
# save preprocessed file end
