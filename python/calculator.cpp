# Simple Calculator in Python

def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        return "Error! Division by zero."
    return a / b

def power(a, b):
    return a ** b

print("=== Simple Python Calculator ===")
print("Operations: +  -  *  /  ^")

while True:
    try:
        num1 = float(input("\nEnter first number: "))
        op = input("Enter operator (+, -, *, /, ^): ")
        num2 = float(input("Enter second number: "))

        if op == '+':
            result = add(num1, num2)
        elif op == '-':
            result = subtract(num1, num2)
        elif op == '*':
            result = multiply(num1, num2)
        elif op == '/':
            result = divide(num1, num2)
        elif op == '^':
            result = power(num1, num2)
        else:
            result = "Invalid operator!"

        print("Result:", result)

        # Ask user if they want to continue
        choice = input("\nDo you want to calculate again? (y/n): ").lower()
        if choice != 'y':
            print("Exiting Calculator. Goodbye!")
            break
    except ValueError:
        print("Invalid input! Please enter numeric values.")
