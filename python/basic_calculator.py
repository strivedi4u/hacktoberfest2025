import turtle
from tkinter import simpledialog, messagebox

# Function to evaluate the user input
def calculator(expression):
    try:
        # Use the eval function to evaluate the expression
        result = eval(expression)
        return result
    except ZeroDivisionError:
        return "Error: Division by zero is not allowed."
    except Exception as e:
        return f"Error: Invalid input. ({e})"

# Function to get user input and display the result
def get_input_and_calculate():
    while True:
        # Get input from user using a dialog box
        user_input = simpledialog.askstring("Input", "Enter an expression (e.g., 3 + 5):")
        
        # Exit condition
        if user_input is None or user_input.lower() == "exit":
            messagebox.showinfo("Goodbye", "Goodbye!")
            break
        
        # Calculate and display the result
        result = calculator(user_input)
        messagebox.showinfo("Output", f"Output: {result}")

# Main function to set up the Turtle screen
def main():
    screen = turtle.Screen()
    screen.title("Simple Calculator")
    
    # Hide the turtle and set up the screen
    turtle.hideturtle()
    turtle.penup()
    turtle.goto(0, 0)
    turtle.write("Click to start", align="center", font=("Arial", 16, "normal"))
    
    # Wait for a click to start the calculator
    screen.onclick(lambda x, y: get_input_and_calculate())
    
    # Main loop
    turtle.done()

if __name__ == "__main__":
    main()
