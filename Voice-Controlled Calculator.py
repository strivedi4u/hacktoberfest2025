import speech_recognition as sr
import pyttsx3
import re

# Initialize components
recognizer = sr.Recognizer()
engine = pyttsx3.init()

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

def calculate(command):
    try:
        numbers = [float(n) for n in re.findall(r'\d+\.?\d*', command)]
        if len(numbers) < 2:
            return "Please provide two numbers."
        if "add" in command:
            return f"{numbers[0]} plus {numbers[1]} equals {numbers[0] + numbers[1]}"
        elif "subtract" in command:
            return f"{numbers[0]} minus {numbers[1]} equals {numbers[0] - numbers[1]}"
        elif "multiply" in command:
            return f"{numbers[0]} times {numbers[1]} equals {numbers[0] * numbers[1]}"
        elif "divide" in command:
            if numbers[1] == 0:
                return "Cannot divide by zero."
            return f"{numbers[0]} divided by {numbers[1]} equals {numbers[0] / numbers[1]}"
        return "Say 'add', 'subtract', 'multiply', or 'divide' with two numbers."
    except:
        return "Invalid input."

def main():
    speak("Welcome to the Voice Calculator. Say operations like 'add 5 and 3'.")
    while True:
        command = recognize_speech()
        if "exit" in command:
            speak("Goodbye!")
            break
        response = calculate(command)
        print(response)
        speak(response)

if __name__ == "__main__":
    main()
