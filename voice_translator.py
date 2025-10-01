import speech_recognition as sr
import pyttsx3
from googletrans import Translator

# Initialize components
recognizer = sr.Recognizer()
engine = pyttsx3.init()
translator = Translator()

def speak(text):
    engine.say(text)
    engine.runAndWait()

def recognize_speech():
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)
        try:
            audio = recognizer.listen(source, timeout=5)
            return recognizer.recognize_google(audio)
        except sr.WaitTimeoutError:
            return "Sorry, I didn't hear anything."
        except sr.UnknownValueError:
            return "Sorry, I couldn't understand you."
        except sr.RequestError:
            return "Speech recognition service error."

def translate_text(text, dest_lang="es"):  # Default to Spanish
    try:
        translated = translator.translate(text, dest=dest_lang)
        return translated.text
    except:
        return "Translation error."

def main():
    speak("Welcome to the Voice Translator. Speak in English to translate to Spanish.")
    while True:
        text = recognize_speech()
        if "exit" in text.lower():
            speak("Goodbye!")
            break
        translated = translate_text(text)
        print(f"English: {text}\nSpanish: {translated}")
        speak(f"Translated to Spanish: {translated}")

if __name__ == "__main__":
    main()
