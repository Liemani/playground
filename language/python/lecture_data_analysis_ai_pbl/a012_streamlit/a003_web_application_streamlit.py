import streamlit as st

st.title("첫 번째 Streamlit 웹!")

st.header("Streamlist(스트림릿)을 시작하겠습니다.")

# streamlit run 파일명.py

st.subheader("웹 앱을 만들기 위한 스트림릿 작은 제목입니다.")

st.text("이것은 일반 텍스트입니다.")

st.write("write()함수를 사용하면, 텍스트, 데이터, 시각화 등 표시 가능")

st.write("streamlit 시각화 애플리케이션!")
st.subheader("Matplotlib 그래프")

import numpy as np
data = np.random.randn(100)
data

if st.button("더하기 버튼") :
    result = 2 + 2

    st.write(f"2+2 = {result}")

user_input = st.text_input("사용자 입력 : ", "기본값")
st.write(f"사용자 입력값 : {user_input}")
