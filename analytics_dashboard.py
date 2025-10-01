import speech_recognition as sr
import pyttsx3
import re

# Initialize speech recognition and text-to-speech
recognizer = sr.Recognizer()
engine = pyttsx3.init()

# Function to convert text to speech
def speak(text):
    engine.say(text)
    engine.runAndWait()

# Function to recognize speech
def recognize_speech():
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)
        try:
            audio = recognizer.listen(source, timeout=5)
            text = recognizer.recognize_google(audio).lower()
            print(f"You said: {text}")
            return text
        except sr.WaitTimeoutError:
            return "Sorry, I didn't hear anything."
        except sr.UnknownValueError:
            return "Sorry, I couldn't understand you."
        except sr.RequestError:
            return "Sorry, there was an issue with the speech recognition service."

# Function to extract numbers from text
def extract_numbers(text):
    numbers = re.findall(r'\d+', text)
    return [int(num) for num in numbers]

# Function to process analytics commands
def process_command(text):
    if "calculate average" in text:
        numbers = extract_numbers(text)
        if numbers:
            average = sum(numbers) / len(numbers)
            return f"The average of {numbers} is {average:.2f}."
        return "No numbers provided for average."
    elif "sum of" in text:
        numbers = extract_numbers(text)
        if numbers:
            total = sum(numbers)
            return f"The sum of {numbers} is {total}."
        return "No numbers provided for sum."
    elif "maximum" in text:
        numbers = extract_numbers(text)
        if numbers:
            max_val = max(numbers)
            return f"The maximum of {numbers} is {max_val}."
        return "No numbers provided for maximum."
    elif "minimum" in text:
        numbers = extract_numbers(text)
        if numbers:
            min_val = min(numbers)
            return f"The minimum of {numbers} is {min_val}."
        return "No numbers provided for minimum."
    else:
        return "Sorry, I only handle basic analytics commands like 'calculate average', 'sum of', 'maximum', or 'minimum' followed by numbers."

# Main loop
def main():
    speak("Welcome to the Analytics Chatbot. Say a command like 'calculate average of 1 2 3'.")
    while True:
        command = recognize_speech()
        if "exit" in command:
            speak("Goodbye!")
            break
        response = process_command(command)
        print(response)
        speak(response)

if __name__ == "__main__":
    main()
