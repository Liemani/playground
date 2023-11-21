from selenium import webdriver
from selenium.webdriver.common.by import By
import time

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

        more_view_cnt = 0
        while True :
            try :
                more_path = "#alex-area > div > div > div > div.cmt_box > div.alex_more > button"
                more_element = driver.find_element(By.CSS_SELECTOR, more_path)
                more_element.click()
                movie_handle = driver.window_handles[-1]
                driver.switch_to.window(movie_handle)
                time.sleep(1)
                more_view_cnt += 1
            except Exception as e :
                break

        rate_path = "ul.list_comment div.ratings"
        rate_elements = driver.find_elements(By.CSS_SELECTOR, rate_path)
        comment_path = "ul.list_comment p.desc_txt"
        comment_elements = driver.find_elements(By.CSS_SELECTOR, comment_path)
        print("평점 갯수 = ", len(rate_elements), " / 리뷰 갯수 = ", len(comment_elements))
        
        for j in range(0, len(rate_elements)) :
            try :
                rate = rate_elements[j].text.strip()
                comment = comment_elements[j].text.strip().replace("\n", "")
                label = 0

                if int(rate) >= 8 :
                    label = 1
                elif int(rate) <= 4:
                    label = 0
                else :
                    label = 2

                file.write(f"{title}\t{rate}\t{comment}\t{label}\n")
            except Exception as e :
                # print(str(e))
                continue

        print("------------------------------------------------------ end[{}] \n".format(more_view_cnt))
        driver.execute_script("window.history.go(-2)")
        time.sleep(1)

    file.close()
    driver.quit()

myMain()
