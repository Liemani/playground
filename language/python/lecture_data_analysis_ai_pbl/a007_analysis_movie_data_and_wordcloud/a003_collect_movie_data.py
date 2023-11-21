# a003_collect_movie_data.py

```
source panel 을 열고 엘리먼트 우클릭 inspect 로 source 의 위치로 jump 할 수 있다
<다음 영화 카테고리에서 웹크롤링 진행>
다음영화 > 랭킹 > 박스오피스 > 월간 기준으로 검색...
해당 URL : https://movie.daum.net/ranking/boxoffice/monthly
10 번 반복
    상세 페이지
    평점 탭메뉴
    더 보기 버튼 없어질 때까지 나오는 전체 리뷰
    영화제목, 평점(1 ~ 10), 리뷰, 레이블(긍정(1)/부정(0)/보통(2))
전처리, 데이터 탐색하면서 시각화
형태소 분석(명사 추출)을 통해 긍정/부정 리뷰 단어 빈도 분석
추출된 명사를 이용해서 긍정/부정 워드클라우드 시각화

<웹크롤링 사용되는 URL>
1.  https://movie.daum.net/ranking/boxoffice/monthly
    제목 수집, 링크 추출

selector path
#mainContent > div > div.box_boxoffice > ol > li:nth-child(1) > div > div.thumb_cont > strong > a

### 웹 크롤링을 위한 라이브러리 : selenium, BeautifulSoop
BeautifullSoop : 정적 페이지에서 수집할 때 주로 사용 (페이지 전환 없이 페이지 내에서만 데이터 수집 시 사용)
selenium : 동적/정적 페이지에서 수집할 때 주로 사용 (페이지 전환(클릭)을 하면서 데이터 수집 시 사용)
```

### 동적 페이지 처리를 위한 라이브러리
from selenium import webdriver

### html 코드 내에서 데이터 추출을 위한 라이브러리
from selenium.webdriver.common.by import By

### completion callback 함수를 사용하는 것이 아니라 직접 sleep() 을 걸어줘야 한다
import time

url = "https://movie.daum.net/ranking/boxoffice/monthly"
driver = webdriver.Chrome()
driver.get(url)
# movie_path = "#mainContent > div > div.box_boxoffice > ol > li:nth-child(1) > div > div.thumb_cont > strong > a"
movie_path = "#mainContent > div > div.box_boxoffice > ol > li > div > div.thumb_cont > strong > a"

### 영화 제목에 대한 모든 태그 추출하기 : 리스트 타입으로 반환됩니다.
movie_elements = driver.find_elements(By.CSS_SELECTOR, movie_path)
print(len(movie_elements))

movie_elements[0].text
movie_elements[0].get_attribute("href")

### 총 30 개 영화 중에 10 개만 수집하기

def getDaumMoviInfo(count) :

def getMovieInfo(index) :

def getMovieTitle(index) :
    movie_elemen

# start
# rate_path = "#comment912792538 > div > div.ratings.rating_2"
# "#alex-area > div > div > div > div.cmt_box > ul.list_comment"
# #comment912792538 > div > p
def myMain() :
    url = "https://movie.daum.net/ranking/boxoffice/monthly"
    driver = webdriver.Chrome()
    driver.get(url)
    movie_path = "#mainContent > div > div.box_boxoffice > ol > li > div > div.thumb_cont > strong > a"
    tab_rate_path = "#mainContent > div > div.box_detailinfo > div.tabmenu_wrap > ul > li:nth-child(4) > a"
    movie_elements = driver.find_elements(By.CSS_SELECTOR, movie_path)
    
    file = open("./data/movie_reviews.txt", "w", encoding = "UTF-8")
    
    for index in range(0, 10, 1) :
        title = movie_elements[index].text.strip()
        print(f"NO[{index}] / 영화 제목[{title}] 데이터 수집 Start .......")
        movie_elements[index].click()
        movie_handle = driver.window_handles[-1]
        driver.switch_to.window(movie_handle)
        time.sleep(1)
        tab_rate_element = driver.find_element(By.CSS_SELECTOR, tab_rate_path)
        tab_rate_element.click()
        movie_handle = driver.window_handles[-1]
        driver.switch_to.window(movie_handle)
        time.sleep(1)
        rate_path = "ul.list_comment div.ratings"
        rate_elements = driver.find_elements(By.CSS_SELECTOR, rate_path)
        comment_path = "ul.list_comment p.desc_txt"
        comment_elements = driver.find_elements(By.CSS_SELECTOR, comment_path)
        print("평점 갯수 = ", len(rate_elements), " / 리뷰 갯수 = ", len(comment_elements))
        
        for j in range(0, len(rate_elements)) :
            rate = rate_elements[j].text.strip()
#             print("평점 = ", rate)
            comment = comment_elements[j].text.strip().replace("\n", "")
#             print("리뷰 = ", comment)
#             [1, 4] [5, 7] [8, 10]
            label = 0
            if int(rate) >= 8 :
                label = 1
            elif int(rate) <= 4:
                label = 0
            else :
                label = 2
#             print(f"{title} / {rate} / {comment} / {label}")
            
            file.write(f"{title}\t{rate}\t{comment}\t{label}\n")
        
        print("------------------------------------------------------ end \n")
        driver.execute_script("window.history.go(-2)")
        time.sleep(1)
    
    file.close()
    driver.quit()
# end
