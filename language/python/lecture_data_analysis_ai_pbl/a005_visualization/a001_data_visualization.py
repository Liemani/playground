# 2023-09-23

## 1 교시
import seaborn as sns

ans = sns.load_dataset("anscombe")
ans.info()
ans.describe()

ans_group = ans.groupby(["dataset"])
ans_group.head(1)

data1 = ans[(ans["dataset"] == "I")]

import matplotlib.pyplot as plt

### 한글처리(폰트 처리) 설정
plt.rc("font", family = "Malgun Gothic")
plt.rc("font", family = "Arial")

### 마이너스 기호 설정
plt.rcParams["axes.unicode_minus"] = False

### 선그래프 그리기
plt.plot(data1["x"], data1["y"], "x")
plt.show()

data1 = ans[ans["dataset"] == "I"]
data2 = ans[ans["dataset"] == "II"]
data3 = ans[ans["dataset"] == "III"]
data4 = ans[ans["dataset"] == "IV"]

print(data1, data2, data3, data4)

## 2 교시
# 우상향
plt.plot(data2["x"], data2["y"], "o")
plt.show()

# 비선형
plt.plot(ans["x"], ans["y"], "o")
plt.show()

# 이상 데이터가 하나 존재
# 우상향
plt.plot(data3["x"], data3["y"], "o")
plt.show()

plt.plot(data4["x"], data4["y"], "o")
plt.show()

# 그래프 객체를 사용해서 4개의 그래프를 하나로 묶어서 시각화
# 그래프 상위 객체
fig = plt.figure()

# 서브플롯(subplot)
# - 큰 그래프에 작은 그래프를 넣는다
# - 몇 개를 넣을건지, 행렬을 어떻게 표현할건지
# - add_subplot(행, 열, 위치번호)
ax1 = fig.add_subplot(2, 2, 1)
ax2 = fig.add_subplot(2, 2, 2)
ax3 = fig.add_subplot(2, 2, 3)
ax4 = fig.add_subplot(2, 2, 4)

ax1.set_title("data1")
ax2.set_title("data2")
ax3.set_title("data3")
ax4.set_title("data4")

ax1.plot(data1["x"], data1["y"], "o", c = "b")
ax2.plot(data2["x"], data2["y"], "o", c = "r")
ax3.plot(data3["x"], data3["y"], "o", c = "g")
ax4.plot(data4["x"], data4["y"], "o", c = "y")

ax1.set_xlabel("x-value")
ax1.set_ylabel("y-value")

ax2.set_xlabel("x-value")
ax2.set_ylabel("y-value")

ax3.set_xlabel("x-value")
ax3.set_ylabel("y-value")

ax4.set_xlabel("x-value")
ax4.set_ylabel("y-value")

fig.suptitle("Anscombe Data")

fig.tight_layout()

plt.show()

# 그래프 종류
# 선그래프
# - 데이터 리스트 타입
plt.plot([1, 2, 3, 4])
plt.show()

# marker o, x, s
plt.plot([1, 2, 3], [1, 2, 3], marker = "s")
plt.title("Line")
plt.show()

plt.title("Visualize line graph")

plt.plot([1, 2, 3, 4], label = "line", linestyle = "-", color = "red")
plt.plot([4, 3, 2, 1], label = "dash", linestyle = "--", color = "blue")
plt.plot([2, 1, 1, 2], label = "dot", linestyle = ":", color = "green")

plt.legend()

plt.xlabel("X-value")
plt.ylabel("Y-value")

plt.show()

#
plt.title("Style practice")

x = [10, 20, 30, 40]
y = [1, 4, 9, 16]

# https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.plot.html
plt.plot(x, y,
    color = "blue",             # c
    linewidth = 5,              # lw
    linestyle = "--",           # ls
    marker = "o",               # m
    markersize = 15,            # ms
    markeredgecolor = "green",  # mec
    markeredgewidth = 5,        # mew
    markerfacecolor = "red",    # mfc
    )

plt.xlim(0, 50)
plt.ylim(-10, 30)

plt.show()
