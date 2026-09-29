'''
Point of Sale (POS) System
Problem:
A small retail store needs a simple Point of Sale system to process daily 
transactions. Each transaction contains multiple items, their prices, and 
quantities. At checkout, the system should calculate the total bill, apply 
a 10% discount if the customer is a member, and generate a receipt.

Programming Task:
Write a program that:

Accepts item names, prices, and quantities.
Applies discounts (if applicable).
Prints the final bill with itemized details.
'''

transactionList = []
discount = 1
totalPrice = 0
receiptFormat = "{:<30} {:<10} {:<10} {:>10}"

print("Enter Item Name, Price, and Quantity.")
print("Type 'END' to finish checkout and generate bill.")
print()

while True:
    item = input("Enter Item Name: ")

    if item.upper() == "END":
        break
    elif item.title() in transactionList:
        print("Error: Item already added.\n")
        continue
    elif not item:
        print("Error: Invalid Item Name.\n")
        continue

    price = input(f"Enter Price of {item}: ")

    if not price.replace('.', '').isdigit() or float(price) < 0:
            print("Error: Invalid Price.\n")
            continue
    elif price.upper() == "END":
        break

    quantity = input(f"Enter Quantity of {item}: ")

    if not quantity.isdigit() or int(quantity) <= 0:
        print("Error: Invalid Quantity.\n")
        continue
    elif quantity.upper() == "END":
        break

    print()
    transactionList.append((item.title(), float(price), int(quantity)))

membership = input("Is the customer a member? (Y/N): ")

if membership.upper() == "Y":
    discount = 0.9

print("-" * 60)
print("FINAL BILL")
print("-" * 60)
print(receiptFormat.format("ITEM", "PRICE", "QUANTITY", "SUBTOTAL"))
print("-" * 60)

for item, price, quantity in transactionList:
    subtotal = price * quantity
    totalPrice += subtotal

    print(receiptFormat.format(item, f"₱{price:.2f}", quantity, f"₱{subtotal:.2f}"))

print("-" * 60)
if membership.upper() == "Y":
    print(receiptFormat.format("DISCOUNT (10%%)", "", "", f"₱-{totalPrice * 0.1:.2f}"))

print(receiptFormat.format("TOTAL", "", "", f"₱{totalPrice * discount:.2f}"))