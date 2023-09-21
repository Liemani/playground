import pandas as pd
import seaborn as sns

tips = sns.load_dataset("tips")
print(len(tips))
tips.info()
print(tips.head(1))

tips[["sex", "tip"]].head(1)
tips_del = tips.drop([2])
# tips_del.loc[2]   # KeyError(key)
tips_del.iloc[2]
tips_del = tips_del.reset_index(drop = True)

c = tips["tip"] > 5
tips[c]

tips[(tips["sex"] == "Male") & (tips["smoker"] == "No")]
tips[tips["smoker"] == "No"]
tips[tips["dat"]

day_series = tips["day"]
c = (day_series == "Sun") | (day_series == "Sat")
tips[c]

c = tips["day"].isin(["Sun", "Sat"])
tips[c]

# if element in list :
tips["total"] = 0
tips["tip"]

tips[c]
tips_del[["day", "bill"]] = "k"
# tips_del["bill"][0] = "10"  # slice
type(tips_del["bill"][0])
tips_del["bill"].loc[0] = "10"

c = tips["sex"] == "Male"

index = 0
while index < len(tips) :
    if tips["sex"][index] == "Male" :
        tips.loc[index, "sex_no"] = 1
    index += 1

tips["sex"].value_counts()

index = 0
while index < len(tips) :
    sector = tips.loc[index]
    tips.loc[index, "new_tip"] = sector["total_bill"] * sector["tip"]
    index += 1

tips["new_tip"] = tips["total_bill"] * tips["tip"]
# astype(<type>)

tips["smoker_str"] = tips["smoker"]
tips["smoker_str"] = tips["smoker_str"].astype(str)
tips2 = tips.astype(str)

# loc(), iloc()??
tips.index

# range 는 끝까지고
# range index 는 끝 전까지인가?

count = 0
for index in range(0, 10, 1) :
# for index in pd.core.indexes.range.RangeIndex(0, 10, 1) :
    count += 1

print(count)

tips.columns

tips.vlaues # numpy.ndarray : 한 타입만 담는다
tips.sort_values(by = ["total_bill"], axis = 0, ascending = False)

filtered_tips = tips.loc[tips["smoker"].str.contains("Y")]

df_temp1 = pd.DataFrame(data = [["Dog", 3], ["Cat", 5], ["Tiger", 2]],
    index = [0, 1, 2],
    columns = ["동물", "나이"])

df_temp2 = pd.DataFrame([["집", 0], ["초원", 0], ["초원", 1]],
    index = [0, 1, 2],
    columns = ["사는곳", "뿔의 갯수"])

pd.concat([df_temp1, df_temp2], axis = 0)
pd.concat([df_temp1, df_temp2], axis = 0, ignore_index = True)
pd.concat([df_temp1, df_temp2], axis = 1)

df_info1 = pd.DataFrame(
    {"고객 번호" : [1001, 1002, 1003], "이름" : ["김", "이", "박"]})
df_info2 = pd.DataFrame(
    {"고객 번호" : [1001, 1001, 1005], "금액" : [10000, 20000, 15000]})

# pd.merge([df_info1, df_info2])
pd.merge(left = df_info1,
    right = df_info2,
    how = "inner",
    left_on = "고객 번호",
    right_on = "고객 번호")

# loc 은 지워진 데이터에 접근하려고 하면 에러가 뜬다고?

pd.merge(left = df_info1,
    right = df_info2,
    how = "left",
#     how = "right",
    left_on = "고객 번호",
    right_on = "고객 번호")

df = pd.DataFrame("data/bicycle.csv")
df = pd.read_csv("data/bicycle.csv", encoding = "euc-kr")

# NaN
# DataFrame::isnull()
df.isnull()
df.notnull()

# <결측치 처리 방법>
# 1. 결측치가 있는 부분을 찾아서, 해당 행/컬럼 부분을 사용할지 말지 결정
# 2. 사용안한다면, 컬럼과 행 중에 어느 부분을 제거할지 결정 (행삭제 또는 컬럼 삭제 처리)
# 3. 사용한다면, 어덯게 사용할지 결정
#   * 결측치가 있는 컬럼 데이터의 "평균"으로 대체해서 사용
#   * 범주형 데이터인 경우 범주의 비율 대비 적절하게 대체
#   * 정수값 또는 실수 데이터인 경운 무조건 0 or 0.0으로 대체
#   * 결측치가 속한 행의 컬럼들과 유사한 타 데이터들의 평균
#   * 결측 데이터의 직전 및 직후 행의 데이터를 평균하여 사용(숫자 데이터인 경우)

df.isnull().sum(axis = 0)
df_drop = df.dropna(axis = 1)

df["대여소명"].dropna(axis = 0)
df["대여거치대"].isnull().value_counts()
df["대여거치대"].isnull().sum(axis = 0)
df["대여거치대"].dropna(axis = 0).isnull().sum(axis = 0)

### 여러 column 의 결측치 제거하기
df[["대여소번호", "대여거치대", "이용시간"]].isnull().sum()
temp = df[["대여소번호", "대여거치대", "이용시간"]]
temp.dropna(axis = 0).isnull().sum()

df.head()
df["이용거리"].isnull().sum()
df["이용거리"].fillna(0)
df["이용거리"].fillna(0).isnull().sum()
df["이용거리"].fillna("missing")    # bad practice

df["이용거리"].mean()
df["이용거리"].fillna(df["이용거리"].mean())

def replace_nan_to_mean_of_column(dataFrame, columns_containing_nan) :
    for column in columns_containing_nan :
        mean = int(dataFrame[column].mean())
        dataFrame[column] = dataFrame[column].fillna(mean)

# attribute
# keep : "first", "last", False
df.duplicated(["이용거리"], keep = "first")

temp.duplicated(["이용거리"]).value_counts()
temp.drop_duplicates(["이용거리"])
df.duplicated().value_counts()

"""
<이상치 데이터>
- 이상치 데이터 처리를 위해서는 결측치 처리를 ㅓㄴ행해야 합니다.
  (결측치를 이상치로 처리하는 경우가 많음)
- 이상 데이터는 숫자값을 가지는 컬럼에 대해서만 계산에 의한 처리가 가능하며,
  문자값에 대해서는 unique()를 통해 확인하여 처리 가능
- 숫자데이터에 대한 이상데이터는 시각화 그래프(boxplot)을 이용해서 확인이 가능함- 이상치 처리는 계산공식으로 처리
"""

import matplotlib.pyplot as plt

df = pd.read_csv()
df = pd.read_csv("data/bicycle_out.csv", encoding = "euc-kr")
temp = df
replace_nan_to_mean_of_column(temp, ["대여거치대", "반납거치대", "이용시간", "이용거리"])

temp.duplicated().value_counts()

plt.boxplot(df["나이"])
plt.show()

(df["나이"] > 100).value_counts()

import numpy as np

np.percentile(df["나이"], [25, 50, 75])
q1, q3 = np.percentile(df["나이"], [25, 75])
iqr = q3 - q1
upper_bound = q3 + iqr * 1.5
lower_bound = q1 - iqr * 1.5

def bounds(series) :
    q1, q3 = np.percentile(series, [25, 75])
    iqr = q3 - q1
    lower_bound = q1 - iqr * 1.5
    upper_bound = q3 + iqr * 1.5
    return lower_bound, upper_bound

def outliers(newDataFrame, column, oldDataFrame) :
    lower_bound, upper_bound = bounds(oldDataFrame[column])
    c = (newDataFrame[column] < lower_bound) | (upper_bound < newDataFrame[column])
    return newDataFrame[c]

"""
<이상치 처리방법>
1. 이상치 계산 공식에 의한 확인(숫자형 컬럼들에 대해서)
2. 제거할지, 대체할지 결정(결측치 처리와 동일하게 진행)
"""

mean = int(temp["나이"].mean())

index = 0
while index < len(temp) :
    lower, upper = bounds(temp["나이"])
    if (temp["나이"][index] < lower) | (upper < temp["나이"][index]) :
        temp.loc[index, "나이"] = mean
    index += 1

copy = df.copy()
copy.loc[outliers, "나이"] = age_mean
