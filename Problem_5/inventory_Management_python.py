inventory = []

while True:
    print("\n=== Inventory Management System ===")
    print("1. Add Product")
    print("2. Sell Product")
    print("3. View Inventory")
    print("4. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        product_id = int(input("Enter Product ID: "))
        name = input("Enter Product Name: ")
        quantity = int(input("Enter Quantity: "))
        price = float(input("Enter Price per Unit: "))

        product = {
            "id": product_id,
            "name": name,
            "quantity": quantity,
            "price": price
        }

        inventory.append(product)

        print("Product added successfully!")

    elif choice == 2:
        product_id = int(input("Enter Product ID: "))
        quantity_sold = int(input("Enter Quantity to Sell: "))

        found = False

        for product in inventory:
            if product["id"] == product_id:
                found = True

                if quantity_sold <= product["quantity"]:
                    product["quantity"] -= quantity_sold
                    print("Sale completed successfully!")
                else:
                    print("Not enough stock!")

                break

        if not found:
            print("Product not found!")

    elif choice == 3:
        total_value = 0

        print("\n=== Inventory Summary ===")

        for product in inventory:
            value = product["quantity"] * product["price"]
            total_value += value

            print(
                f"ID: {product['id']} | "
                f"Name: {product['name']} | "
                f"Quantity: {product['quantity']} | "
                f"Price: {product['price']:.2f} | "
                f"Value: {value:.2f}"
            )

        print(f"Total Stock Value: {total_value:.2f}")

    elif choice == 4:
        print("Exiting program...")
        break

    else:
        print("Invalid choice!")