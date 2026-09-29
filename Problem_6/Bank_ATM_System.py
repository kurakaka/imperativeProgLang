acc_numbers = ["1001", "1002", "1003"]
passwords = ["pass123", "secret456", "atm789"]
balances = [5000.00, 12000.50, 300.00]

choice = 'y'

while choice.lower() == 'y':
    print("\n=== BANK ATM WITHDRAWAL SYSTEM ===")
    input_acc = input("Enter Account Number: ")
    input_pass = input("Enter Password: ")

    found_index = -1

    if input_acc == acc_numbers[0] and input_pass == passwords[0]:
        found_index = 0
    elif input_acc == acc_numbers[1] and input_pass == passwords[1]:
        found_index = 1
    elif input_acc == acc_numbers[2] and input_pass == passwords[2]:
        found_index = 2

    if found_index != -1:
        print("\nLogin Successful!")
        print(f"\nCurrent Balance: ${balances[found_index]:.2f}")
        withdraw_amount = float(input("Enter Withdrawal Amount: $"))

        if withdraw_amount <= 0:
            print("\nInvalid withdrawal amount.")
        elif withdraw_amount > balances[found_index]:
            print("\nTransaction Failed: Insufficient balance!")
        else:
            balances[found_index] = balances[found_index] - withdraw_amount
            print("\nTransaction Successful!")
            print(f"Remaining Balance: ${balances[found_index]:.2f}")
    else:
        print("\nError: Invalid Account Number or Password!")

    choice = input("\nDo you want to perform another transaction? (y/n): ")

print("\nThank you for using our ATM. Goodbye!")