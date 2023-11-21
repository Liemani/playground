import pandas as pd
import matplotlib.pyplot as pyplot
import folium
import plotly.express as px
import warnings

pyplot.rcParams["axes.unicode_minus"] = False

warnings.filterwarnings(action = "ignore")

def print_wifi_as(dataframe, column) :
    total = 0
    for category in dataframe[column].unique() :
        length = len(dataframe[dataframe[column] == category])
        print(category, ":", length)
        total += length
    print("total :", total)

df["설치시도명"].value_counts()

df_grouped = df.groupby(["설치시도명"])
df_grouped.head(1)

df_grouped = df.groupby(["설치시설구분"])
df_grouped.head(1)

df_grouped = df.groupby(["서비스제공사명"])
df_grouped.head(1)

df.groupby(by = ["설치시도명", "설치시설구분", "서비스제공사명", "설치갯수"])
# - count() : NaN 값을 제외하고 count
# - size() : NaN 값을 포함해서 count
# - reset_index() : 그룹화 데이터를 행렬의 데이터프레임 형태로 변환
group_data = df.groupby(by = ["설치시도명",
    "설치시설구분",
    "서비스제공사명"]).size().reset_index(name = "설치수")

fig = px.bar(group_data, x = "설치시도명", y = "설치수")
fig.show()

fig = px.histogram(group_data, x = "설치시도명", y = "설치수")
fig.show()

fig = px.histogram(group_data, x = "설치시설구분", y = "설치수")
fig.show()

# name: what column should use
# values: ratio
fig = px.pie(group_data, names = "설치시도명", values = "설치수")
fig.show()

fig = px.pie(group_data, names = "설치시도명", values = "설치수")
fig.update_traces(textposition = "inside", textinfo = "percent+label")
fig.show()

fig = px.pie(group_data, names = "설치시도명", values = "설치수")
fig.update_traces(
    textposition = "inside",
    textinfo = "percent+label",
    textfont_size = 20,
    marker = dict(line = dict(width = 1)))
fig.show()

dj_df = df[df["설치시도명"] == "대전광역시"]

fig = px.pie(dj_df, names = "설치시군구명")
fig.update_traces(
    textposition = "inside",
    textinfo = "percent+label",
    textfont_size = 20,
    marker = dict(line = dict(width = 1)))
fig.show()

# nice
fig = px.histogram(dj_df, x="설치시군구명", color="설치시설구분")
fig.show()

# 집계..갯수, 평균, 최대, 최소
group_dj = dj_df.groupby(by = ["설치연월", "설치시군구명", "설치시설구분", "서비스제공사명", "관리기관명"])

fig = px.histogram(dj_df, x="설치시군구명", color="설치시설구분")
fig.show()

fig = px.histogram(group_dj, x="설치시군구명", color="설치시설구분")
fig.show()

group_dj = group_dj.size().reset_index(name = "설치수")

fig = px.histogram(group_dj, x = "설치시군구명", y = "설치수", color = "설치시설구분")
fig.show()

fig = px.pie(group_dj, names = "설치시군구명", values = "설치수")
fig.update_traces(
    textposition = "inside",
    textinfo = "percent+label",
    textfont_size = 20,
    marker = dict(line = dict(width = 1)))
fig.show()
