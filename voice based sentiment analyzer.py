import speech_recognition as sr
import pyttsx3
from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer

# Initialize components
recognizer = sr.Recognizer()
engine = pyttsx3.init()
analyzer = SentimentIntensityAnalyzer()

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

def analyze_sentiment(text):
    scores = analyzer.polarity_scores(text)
    compound = scores["compound"]
    if compound >= 0.05:
        return "positive"
    elif compound <= -0.05:
        return "negative"
    return "neutral"

def main():
    speak("Welcome to the Sentiment Analyzer. Speak to analyze your mood.")
    while True:
        text = recognize_speech()
        if "exit" in text.lower():
            speak("Goodbye!")
            break
        sentiment = analyze_sentiment(text)
        response = f"Your sentiment is {sentiment}."
        print(f"Text: {text}\nSentiment: {sentiment}")
        speak(response)

if __name__ == "__main__":
    main()
