from flask import Flask, render_template, request
from datetime import datetime

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate-age', methods=['POST'])
def calculate_age():
    birthdate_str = request.form['birthdate']  # Get birthdate from the form
    birthdate = datetime.strptime(birthdate_str, "%Y-%m-%d")
    today = datetime.today()

    # Calculate age
    age = today.year - birthdate.year
    if (today.month, today.day) < (birthdate.month, birthdate.day):
        age -= 1

    # Pass the age to the template to display it
    return render_template('index.html', age=age)

if __name__ == "__main__":
    app.run(debug=True)
