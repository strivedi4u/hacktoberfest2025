from tkinter import *
from tkinter import ttk, messagebox
from googletrans import Translator, LANGUAGES
from textblob import TextBlob

# Create the main application window
root = Tk()
root.title("Google Translator")
root.geometry("1080x400")

# Initialize the translator and language dictionary
translator = Translator()
LANGUAGES_INV = {v: k for k, v in LANGUAGES.items()}

# Update labels based on selected languages
def label_change():
    label1.configure(text=combo1.get())
    label2.configure(text=combo2.get())

# Translate text based on user input
def translate_now():
    text_ = text1.get(1.0, END).strip()
    from_lang = LANGUAGES_INV.get(combo1.get(), 'en')
    to_lang = LANGUAGES_INV.get(combo2.get(), 'en')

    if text_:
        try:
            # Detect source language if not selected
            detected_lang = from_lang if from_lang != 'en' else translator.detect(text_).lang
            translated = translator.translate(text_, src=detected_lang, dest=to_lang)
            text2.delete(1.0, END)
            text2.insert(END, translated.text)
        except Exception as e:
            messagebox.showerror("Translation Error", f"An error occurred: {e}")
    else:
        messagebox.showwarning("Input Error", "Please enter text to translate.")

# Set up the application layout
def setup_layout():
    # Language selection dropdowns
    combo1.place(x=110, y=20)
    combo1.set("SELECT LANGUAGE")
    combo1.bind("<<ComboboxSelected>>", lambda e: label_change())

    combo2.place(x=730, y=20)
    combo2.set("SELECT LANGUAGE")
    combo2.bind("<<ComboboxSelected>>", lambda e: label_change())

    # Labels for language selection
    label1.place(x=10, y=50)
    label2.place(x=620, y=50)

    # Frames for text input and output
    f.place(x=10, y=118, width=448, height=210)
    f1.place(x=620, y=118, width=448, height=210)

    # Text areas for input and output
    text1.place(x=0, y=8, width=430, height=200)
    text2.place(x=0, y=8, width=430, height=200)

    # Scrollbars for text areas
    scrollbar1.pack(side="right", fill="y")
    scrollbar1.configure(command=text1.yview)
    text1.configure(yscrollcommand=scrollbar1.set)

    scrollbar2.pack(side="right", fill="y")
    scrollbar2.configure(command=text2.yview)
    text2.configure(yscrollcommand=scrollbar2.set)

    # Translate button
    translate.place(x=480, y=250)

# Initialize UI components
languageV = list(LANGUAGES.values())
combo1 = ttk.Combobox(root, values=languageV, font="Roboto 14", state="readonly")
combo2 = ttk.Combobox(root, values=languageV, font="Roboto 14", state="readonly")
label1 = Label(root, text="SELECT LANGUAGE", font="Segoe 30 bold", bg="white", width=18, bd=5, relief=GROOVE)
label2 = Label(root, text="ENGLISH", font="Segoe 38 bold", bg="white", width=18, bd=5, relief=GROOVE)

f = Frame(root, bg="Black", bd=5)
f1 = Frame(root, bg="Black", bd=5)
text1 = Text(f, font="Roboto 20", bg="white", relief=GROOVE, wrap=WORD)
text2 = Text(f1, font="Roboto 20", bg="white", relief=GROOVE, wrap=WORD)
scrollbar1 = Scrollbar(f)
scrollbar2 = Scrollbar(f1)
translate = Button(root, text="Translate", font="Roboto 15 bold italic", activebackground="purple", cursor="hand2", bd=5, bg="red", fg="white", command=translate_now)




# Setup layout and start the main loop
setup_layout()
root.configure(bg="white")
root.mainloop()
