import speech_recognition as sr
import pyttsx3
from pyowm import OWM
from pyowm.utils.config import get_default_config

# Initialize components
recognizer = sr.Recognizer()
engine = pyttsx3.init()
config_dict = get_default_config()
config_dict['language'] = 'en'
owm = OWM('your_api_key')  # Replace with your OpenWeatherMap API key

def speak(text):
    engine.say(text)
    engine.runAndWait()

def recognize_speech():
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)
        try:
            audio = recognizer.listen(source, timeout=5)
            return recognizer.recognize_google(audio).lower()
        except sr.WaitTimeoutError:
            return "Sorry, I didn't hear anything."
        except sr.UnknownValueError:
            return "Sorry, I couldn't understand you."
        except sr.RequestError:
            return "Speech recognition service error."

def get_weather(city):
    try:
        mgr = owm.weather_manager()
        observation = mgr.weather_at_place(city)
        weather = observation.weather
        temp = weather.temperature('celsius')['temp']
        status = weather.detailed_status
        return f"The weather in {city} is {status} with a temperature of {temp} degrees Celsius."
    except:
        return "Could not fetch weather data."

def main():
    speak("Welcome to the Weather Assistant. Say a city name for weather updates.")
    while True:
        command = recognize_speech()
        if "exit" in command:
            speak("Goodbye!")
            break
        if "weather" in command:
            city = command.replace("weather", "").strip()
            response = get_weather(city)
        else:
            response = "Please say 'weather' followed by a city name."
        print(response)
        speak(response)

if __name__ == "__main__":
    main()
