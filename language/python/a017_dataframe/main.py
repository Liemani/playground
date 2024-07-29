"""
column_list = train_df.columns.tolist()

for index in range(5) :
  print(index)

for index in range(len(train_df)) :
  age = train_df.loc[index, '피해운전자 연령']
  len(age) != 0

# start
def checkDateColumnFormat(df) :
  spaceCharacterCount = {}
  for index in range(len(df)) :
    dateContent = df.loc[index, '사고일시']
    count = dateContent.count(' ')
    spaceCharacterCount.setdefault(count, 0)
    spaceCharacterCount[count] += 1
  print(spaceCharacterCount)
# end

train_df.to_csv('a003_temp.csv', index=False)
"""

import pandas as pd
import numpy as np

train_org = pd.read_csv('data/train.csv')
train_df = train_org.copy()

train_df = train_df.dropna(axis = 0)

# start
def checkDateColumnFormat(df, column, pattern) :
  describe = df[column].str.match(pattern).describe()
  print(describe)
# end

# 사고일시
time_pattern = r'(\d{4})-(\d{1,2})-(\d{1,2}) (\d{1,2})'
checkDateColumnFormat(train_df, '사고일시', time_pattern)
train_df[['연', '월', '일', '시간']] = train_df['사고일시'].str.extract(time_pattern)
train_df.drop(columns=['사고일시'], inplace=True)

# 시군구
localePattern = r'([^ ]+) ([^ ]+) ([^ ]+)'
checkDateColumnFormat(train_df, '시군구', localePattern)
train_df[['시', '군구', '읍면동']] = train_df['시군구'].str.extract(localePattern)
train_df.drop(columns=['시군구'], inplace=True)

# 도로형태
roadPattern = r'([^ ]+) - ([^ ]+)'
checkDateColumnFormat(train_df, '도로형태', roadPattern)
train_df[['도로형태1', '도로형태2']] = train_df['도로형태'].str.extract(roadPattern)
train_df.drop(columns=['도로형태'], inplace=True)

# 가해운전자 연령
# train_df['가해운전자 연령'].unique()
c = train_df['가해운전자 연령'] == '미분류'
train_df.loc[c, '가해운전자 연령'] = '세'
roadPattern = r'(\d)'
checkDateColumnFormat(train_df, '도로형태', roadPattern)



# 2023-11-19
data = [['a', 3], ['b', 2], ['c', 1]]
df = pd.DataFrame(data, columns=['word', 'count'])
df.loc[0, 'test'] = ''

temp_df = pd.read_csv('data/temp.csv')

train_df['피해운전자 차종'].isna()

c = train_df['피해운전자 차종'].isna()
train_df.drop(c, inplace=True)

train_df = train_df['피해운전자 차종'].dropna(axis = 0)
train_df = train_df.dropna(axis = 0)
