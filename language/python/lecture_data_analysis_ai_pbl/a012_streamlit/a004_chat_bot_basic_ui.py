import streamlist as st

def main() :
    st.set_page_config(
        page_title = "음성 비서 프로그램",
        layout = "wide",
    )

    st.header("음성 비서 프로그램")

    st.markdown("---")

    with st.expander("음성비서 프로그램에 대하여", expanded=True) :
        st.write(
            """
            - 음성비서 프로그램의 UI는 스트림릿을 활용했습니다.
            - STT는 OpenAI의 Whisper AI를 활용했습니다.
            - 답변은 OpenAI의 GPT 모델을 활용했습니다.
            - TTS는 구글의 gTTS를 활용했습니다.
            """
        )

    with st.sidebar :
        openai.api_key = st.text_input(
            label="OpenAi API Key 입력",
            placeholder="Enter Your API"
        )

if __name__ == "__main__" :
    main()
