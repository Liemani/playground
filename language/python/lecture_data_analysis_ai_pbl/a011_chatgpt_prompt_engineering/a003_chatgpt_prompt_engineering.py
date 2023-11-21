import psutil
import time

cnt = 5

for i in range(cnt) :
    cpu_ = psutil.cpu_percent(interval=1)
    ram_ = psutil.virtual_memory().percent
    print(f"반복[{i}] : CPU사용량[{cpu_}%] RAM사용량[{ram_}%]")
    time.sleep(1)

print("프로그램 종료!!")

# start
# 이건 또 jupyter에서는 되는데 실시간에서는 안되네
# pip install googletrans==4.0.0-rc1
from googletrans import Translator

eng_file = "./data/eng.txt"
kor_file = "./data/kor.txt"

translator = Translator()

try :
    with open(eng_file, "r", encoding = "utf-8") as eng_file :
        eng_text = eng_file.read()
    print(f"[영문 원본] --------\n{eng_text}")
    kor_translation = translator.translate(eng_text, src = "en", dest = "ko")
    print(f"[한글 번역] --------\n{kor_translation.text}")
    with open(kor_file, "w", encoding="utf-8") as kor_file :
        kor_file.write(kor_translation.text)
except Exception as e :
    print(f"오류 발생 : {str(e)}")
# end
