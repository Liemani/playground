# a001_analyze_population_decline.py
# https://kosis.kr/statHtml/statHtml.do?orgId=101&tblId=DT_1B04005N&conn_path=I3
# hitmap, catogram

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

plt.rc("font", family="AppleGothic")
plt.rcParams["axes.unicode_minus"] = False

import warnings
warnings.filterwarnings("ignore")

population = pd.read_excel("./data/01_population_raw_data.xlsx", header = 1)

population.ffill(inplace = True)

population.rename(
        columns = {
            "행정구역(동읍면)별(1)" : "광역시도",
            "행정구역(동읍면)별(2)" : "시도",
            "계" : "인구수"
        },
        inplace = True)

population.rename(
    columns = {
        "항목" : "구분"
    },
    inplace = True)

population = population.drop(population[population["시도"] == "소계"].index)

population.loc[population["구분"] == "총인구수 (명)", "구분"] = "합계"
population.loc[population["구분"] == "남자인구수 (명)", "구분"] = "남자"
population.loc[population["구분"] == "여자인구수 (명)", "구분"] = "여자"

population[population["시도"] == "소계"]
populationBackup = population.copy()

population["20-39"] = population["20 - 24세"] + population["25 - 29세"] + population["30 - 34세"] + population["35 - 39세"]

population["65세이상"] = population["65 - 69세"] + population["70 - 74세"] + population["75 - 79세"] + population["80 - 84세"] + population["85 - 89세"] + population["90 - 94세"] + population["95 - 99세"] + population["100+"]

pop = pd.pivot_table(population,
        index = ["광역시도", "시도"],
        columns = ["구분"],
        values = ["인구수", "20-39", "65세이상"],
        aggfunc = "mean"
        )

pop["20-39", "여자"]
pop["65세이상", "합계"]

pop["소멸비율"] = pop["20-39", "여자"] / (pop["65세이상", "합계"] / 2)
pop["소멸위기지역"] = pop["소멸비율"] < 1.0

pop[pop["소멸위기지역"] == True].index.get_level_values(1)

pop.reset_index(inplace = True)

# make multi index column to index start
pop.columns
pop.columns.get_level_values(0)
pop.columns.get_level_values(1)
# make multi index column to index end
for cols1, cols2 in pop.columns :
    print(cols1 + cols2)

tmp_columns = [cols1 + cols2 for cols1, cols2 in pop.columns]
pop.columns = tmp_columns

pop["시도"].unique()

si_name = [None] * len(pop)

tmp_gu_dict = {'수원' : ['장안구', '권선구', '팔달구', '영통구'],
               '성남' : ['수정구', '중원구', '분당구'],
               '안양' : ['만안구', '동안구'],
               '안산' : ['상록구', '단원구'],
               '고양' : ['덕양구', '일산동구', '일산서구'],
               '용인' : ['처인구', '기흥구', '수지구'],
               '청주' : ['상당구', '서원구', '흥덕구', '청원구'],
               '천안' : ['동남구', '서북구'],
               '전주' : ['완산구', '덕진구'],
               '포항' : ['남구', '북구'],
               '창원' : ['의창구', '성산구', '진해구', '마산합포구', '마산회원구'],
               '부천' : ['오정구', '원미구', '소사구']}

"""
1. "광역시도" 데이터 중에 끝 세 자리가 광역시, 특별시, 자치시로 끝나지 않으면, 일반 시 또는 군으로 처리
2. 강원도와 경상남도에는 동일한 이름을 가지는 "고성군"이 있음
3. 일반 시인데 구를 갖는 경우 처리
4. 세종특별자치시는 그냥 "세종"으로 처리
"""

temp = pop[pop["광역시도"] == "경상남도"]

for n in pop.index :
    if pop["광역시도"][n][-3 : ] not in ["광역시", "특별시", "자치시"] :
        if pop["시도"][n][ : -1] == "고성" and pop["광역시도"][n] == "강원도" :
            si_name[n] = "고성(강원)"
        elif pop["시도"][n][ : -1] == "고성" and pop["광역시도"][n] == "경상남도" :
            si_name[n] = "고성(경남)"
        else :
            si_name[n] = pop["시도"][n][ : -1]
        for keys, values in tmp_gu_dict.items() :
            if pop["시도"][n] in values :
                if len(pop["시도"][n]) == 2 :
                    si_name[n] = keys + " " + pop["시도"][n]
                elif pop["시도"][n] in ["마산합포구", "마산회원구"] :
                    si_name[n] = keys + " " + pop["시도"][n][2 : -1]
                else :
                    si_name[n] = keys + " " + pop["시도"][n][ : -1]
    elif pop["광역시도"][n] == "세종특별자치시" :
        si_name[n] = "세종"
    else :
        if len(pop["시도"][n]) == 2 :
            si_name[n] = pop["광역시도"][n][ : 2] + " " + pop["시도"][n]
        else :
            si_name[n] = pop["광역시도"][n][ : 2] + " " + pop["시도"][n][ : -1]

del pop["20-39남자"]
del pop["65세이상남자"]
del pop["65세이상여자"]

pop["ID"] = si_name

if "고성(강원)" in si_name :
    print("yes")
else :
    print("no")

draw_korea_raw = pd.read_excel("./data/02_draw_korea_raw.xlsx")

draw_korea_raw.stack()
draw_korea_raw_stacked = pd.DataFrame(draw_korea_raw.stack())
draw_korea_raw_stacked.reset_index(inplace = True)

draw_korea_raw_stacked.rename(
    columns = {
        "level_0" : "y",
        "level_1" : "x",
        0 : "ID",
    },
    inplace = True,
)

draw_korea = draw_korea_raw_stacked.copy()

BORDER_LINES = [
    # 인천
    [(5,1), (5,2), (7,2), (7,3), (11,3), (11,0)],

    # 서울
    [(5,4), (5,5), (2,5), (2,7), (4,7), (4,9), (7,9),
     (7,7), (9,7), (9,5), (10,5), (10,4), (5,4)],

    # 경기도
    [(1,7), (1,8), (3,8), (3,10), (10,10), (10,7),
     (12,7), (12,6), (11,6), (11,5), (12, 5), (12,4),
     (11,4), (11,3)],

    # 강원도
    [(8,10), (8,11), (6,11), (6,12)],

    # 충청북도
    [(12,5), (13,5), (13,4), (14,4), (14,5), (15,5),
     (15,4), (16,4), (16,2)],

    # 전라북도
    [(16,4), (17,4), (17,5), (16,5), (16,6), (19,6),
     (19,5), (20,5), (20,4), (21,4), (21,3), (19,3), (19,1)],

    # 대전시
    [(13,5), (13,6), (16,6)],

    #세종시
    [(13,5), (14,5)],

    #광주
    [(21,2), (21,3), (22,3), (22,4), (24,4), (24,2), (21,2)],

    #전라남도
    [(20,5), (21,5), (21,6), (23,6)],

    #충청북도
    [(10,8), (12,8), (12,9), (14,9), (14,8), (16,8), (16,6)],

    #경상북도
    [(14,9), (14,11), (14,12), (13,12), (13,13)],

    #대구
    [(15,8), (17,8), (17,10), (16,10), (16,11), (14,11)],

    #부산
    [(17,9), (18,9), (18,8), (19,8), (19,9), (20,9), (20,10), (21,10)],

    #울산
    [(16,11), (16,13)],

    #울릉도
    [(9,14), (9,15)],

    #완도, 제주
    [(27,5), (27,6), (25,6)],
]

# cartogram start
plt.figure(figsize = (8, 11))
plt.title("시도 경계선 시각화")

for path in BORDER_LINES :
    ys, xs = zip(*path)
    plt.plot(xs, ys, c = "black", lw = 1.5)

    print("idx, row ==> ", idx, row)
    print(row["ID"].split())
for idx, row in draw_korea.iterrows() :
    if len(row["ID"].split()) == 2 :
        dispname = "{}\n{}".format(row["ID"].split()[0], row["ID"].split()[1])
    elif row["ID"][ : 2] == "고성" :
        dispname = "고성"
    else :
        dispname = row["ID"]
    if len(dispname.splitlines()[-1]) >= 3 :
        fontsize, linespacing = 9.5, 1.5
    else :
        fontsize, linespacing = 11, 1.2
    plt.annotate(dispname,
        (row["x"] + 0.5, row["y"] + 0.5),
        weight = "bold",
        fontsize = fontsize,
        ha = "center",
        va = "center",
        linespacing = linespacing)

plt.gca().invert_yaxis()

plt.axis("off")

plt.tight_layout()

plt.savefig("./data/cartogram.png")

plt.show()
# cartogram end

print(len(draw_korea), len(pop))
# remove region doesn't contained in draw_korea from pop start
draw_korea["ID"].unique()
set(draw_korea["ID"].unique())
pop["ID"].unique()
tmp_list = set(pop["ID"].unique()) - set(draw_korea["ID"].unique())

for tmp in tmp_list :
    pop = pop.drop(pop[pop["ID"] == tmp].index)
# remove region doesn't contained in `draw_korea` from `pop` end
tmp_list = set(draw_korea["ID"].unique()) - set(pop["ID"].unique())

tmp = draw_korea.copy()
for temp in tmp_list :
    tmp = tmp.drop(tmp[tmp["ID"] == temp].index)

pop2 = pd.merge(
    left = pop,
    right = tmp,
    how = "left",
    on = ["ID"])

mapdata = pd.pivot_table(pop2,
        index = ["y"],
        columns = ["x"],
        values = ["인구수합계"],
        aggfunc = "mean"
        )

masked_mapdata = np.ma.masked_where(np.isnan(mapdata), mapdata)

def drawKorea(targetData, blockedMap, cmapname) :
    vmin = min(blockedMap[targetData])
    vmax = max(blockedMap[targetData])
    mapdata = blockedMap.pivot_table(
        index = "y",
        columns = "x",
        values = targetData)
    masked_mapdata = np.ma.masked_where(np.isnan(mapdata), mapdata)
    plt.figure(figsize = (9, 11))
    plt.pcolor(
        masked_mapdata,
        vmin = vmin,
        vmax = vmax,
        cmap = cmapname,
        edgecolor = "#aaaaaa",
        linewidth = 0.5)
    for path in BORDER_LINES :
        ys, xs = zip(*path)
        plt.plot(
            xs,
            ys,
            c = "black",
            lw = 2)
    whitelabelmin = min(blockedMap[targetData]) + (max(blockedMap[targetData]) - min(blockedMap[targetData])) * 0.5
    for idx, row in blockedMap.iterrows() :
        if len(row["ID"].split()) == 2 :
            dispname = "{}\n{}".format(row["ID"].split()[0], row["ID"].split()[1])
        elif row["ID"][ : 2] == "고성" :
            dispname = "고성"
        else :
            dispname = row["ID"]
        if len(dispname.splitlines()[-1]) >= 3 :
            fontsize, linespacing = 9.5, 1.5
        else :
            fontsize, linespacing = 11, 1.2
        annocolor = "white" if row[targetData] > whitelabelmin else "black"
        plt.annotate(dispname,
            (row["x"] + 0.5, row["y"] + 0.5),
            weight = "bold",
            fontsize = fontsize,
            ha = "center",
            va = "center",
            color = annocolor,
            linespacing = linespacing)
    plt.gca().invert_yaxis()
    plt.axis("off")
    cb = plt.colorbar(shrink = 0.1, aspect = 10)
    cb.set_label(targetData)
    plt.tight_layout()
    plt.show()

drawKorea("인구수합계", pop2, "Blues")

# analysis start
# 하얀색일수록 소멸 위험 높음
# analysis start

pop2["소멸위기지역"] = [1 if con else 0 for con in pop2["소멸위기지역"]]
drawKorea("소멸위기지역", pop2, "Reds")

def drawKorea2(targetData, blockedMap, cmapname) :
    tmp_max = max([
        np.abs(min(blockedMap[targetData])),
        np.abs(max(blockedMap[targetData]))
    ])
    vmin = -tmp_max
    vmax = tmp_max
    mapdata = blockedMap.pivot_table(
        index = "y",
        columns = "x",
        values = targetData)
    masked_mapdata = np.ma.masked_where(np.isnan(mapdata), mapdata)
    plt.figure(figsize = (9, 11))
    plt.pcolor(
        masked_mapdata,
        vmin = vmin,
        vmax = vmax,
        cmap = cmapname,
        edgecolor = "#aaaaaa",
        linewidth = 0.5)
    for path in BORDER_LINES :
        ys, xs = zip(*path)
        plt.plot(
            xs,
            ys,
            c = "black",
            lw = 2)
    whitelabelmin = 20.0
    for idx, row in blockedMap.iterrows() :
        if len(row["ID"].split()) == 2 :
            dispname = "{}\n{}".format(row["ID"].split()[0], row["ID"].split()[1])
        elif row["ID"][ : 2] == "고성" :
            dispname = "고성"
        else :
            dispname = row["ID"]
        if len(dispname.splitlines()[-1]) >= 3 :
            fontsize, linespacing = 9.5, 1.5
        else :
            fontsize, linespacing = 11, 1.2
        annocolor = "white" if row[targetData] > whitelabelmin else "black"
        plt.annotate(dispname,
            (row["x"] + 0.5, row["y"] + 0.5),
            weight = "bold",
            fontsize = fontsize,
            ha = "center",
            va = "center",
            color = annocolor,
            linespacing = linespacing)
    plt.gca().invert_yaxis()
    plt.axis("off")
    cb = plt.colorbar(shrink = 0.1, aspect = 10)
    cb.set_label(targetData)
    plt.tight_layout()
    plt.show()

# visualize female population start
pop2["여성비"] = (pop2["인구수여자"] / pop2["인구수합계"] - 0.5) * 100.0
# visualize female population end

drawKorea2("여성비", pop2, "RdBu")

# analyze start
# 화천, 인천 웅진, 울릉 등의 경우 여성 비율이 낮음
# analyze end

pop2["2030여성비"] = (pop2["20-39여자"] / pop2["20-39합계"] - 0.5) * 100.0

drawKorea2("2030여성비", pop2, "RdBu")

# analyze start
# 전국적으로 2030 세대의 여성 인구 비율은 서울지역을 제외하고 낮은 분포를 나타냄
# analyze end

pop_folium = pop2.set_index("ID")

import folium
import json

geo_path = "./data/03_skorea_municipalities_geo_simple.json"
geo_str = json.load(open(geo_path, encoding = "utf-8"))

# visualize to global map start
map = folium.Map(location = [36.2002, 127.054], zoom_start = 7)
map.choropleth(
    geo_data = geo_str,
    data = pop_folium["인구수합계"],
    columns = [pop_folium.index, pop_folium["인구수합계"]],
    fill_color = "YlGnBu",
    key_on = "feature.id")
# visualize to global map end

# visualize to global map of decline start
map = folium.Map(location = [36.2002, 127.054], zoom_start = 7)
map.choropleth(
    geo_data = geo_str,
    data = pop_folium["소멸위기지역"],
    columns = [pop_folium.index, pop_folium["소멸위기지역"]],
    fill_color = "PuRd",
    key_on = "feature.id")
# visualize to global map of decline end
pop.to_csv("./data/pop.csv", encoding = "utf-8", sep = ",")
pop2.to_csv("./data/pop2.csv", encoding = "utf-8", sep = ",")
draw_korea.to_csv("./data/draw_korea.csv", encoding = "utf-8", sep = ",")
pop_folium.to_csv("./data/pop_folium.csv", encoding = "utf-8", sep = ",")
