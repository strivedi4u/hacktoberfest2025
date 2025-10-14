def tip_calculator():
    # Get user input
    total_bill = float(input("Enter the total bill amount: $"))
    tip_percentage = float(input("Enter the tip percentage (e.g., 15 for 15%): "))
    number_of_people = int(input("Enter the number of people sharing the bill: "))

    # Calculate tip and total amount
    tip_amount = total_bill * (tip_percentage / 100)
    total_amount = total_bill + tip_amount
    amount_per_person = total_amount / number_of_people

    # Output results
    print("\n--- Tip Calculator Results ---")
    print(f"Total bill amount: ${total_bill:.2f}")
    print(f"Tip amount: ${tip_amount:.2f}")
    print(f"Total amount (including tip): ${total_amount:.2f}")
    print(f"Amount per person: ${amount_per_person:.2f}")

# Run the tip calculator
tip_calculator()
