from google.cloud import speech_v1p1beta1 as speech
from google.cloud import translate_v2 as translate
from gtts import gTTS
import pygame
import io

def speech_to_text(audio_file):
    client = speech.SpeechClient()

    with open(audio_file, "rb") as audio_file:
        content = audio_file.read()

    audio = speech.RecognitionAudio(content=content)
    config = speech.RecognitionConfig(
        encoding=speech.RecognitionConfig.AudioEncoding.LINEAR16,
        sample_rate_hertz=16000,
        language_code="en-US",  # Adjust the language code if needed
    )

    response = client.recognize(config=config, audio=audio)

    return response.results[0].alternatives[0].transcript

def translate_text(text, target_language="es"):
    client = translate.Client()

    translation = client.translate(text, target_language=target_language)

    return translation["input"], translation["translatedText"]

def text_to_speech(text, lang="en"):
    tts = gTTS(text=text, lang=lang, slow=False)
    audio_stream = io.BytesIO()
    tts.save(audio_stream)
    audio_stream.seek(0)
    return audio_stream

def play_audio(audio_stream):
    pygame.mixer.init()
    pygame.mixer.music.load(audio_stream)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pygame.time.Clock().tick(10)

if __name__ == "__main__":
    audio_file = "your_audio_file.wav"  # Replace with the path to your audio file

    # Step 1: Speech to Text
    transcribed_text = speech_to_text(audio_file)
    print("Transcribed Text:", transcribed_text)

    # Step 2: Translation
    input_text, translated_text = translate_text(transcribed_text, target_language="es")
    print("Input Text:", input_text)
    print("Translated Text:", translated_text)

    # Step 3: Text to Speech
    audio_stream = text_to_speech(translated_text, lang="es")

    # Step 4: Play the audio
    play_audio(audio_stream)
