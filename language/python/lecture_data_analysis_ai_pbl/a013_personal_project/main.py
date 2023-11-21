import streamlit

def main() :
  streamlit.markdown("---")

  with streamlit.sidebar :
    model = streamlit.radio(label="select", options=["a", "b", "c"])

    streamlit.markdown("---")

if __name__ == "__main__" :
  main()
