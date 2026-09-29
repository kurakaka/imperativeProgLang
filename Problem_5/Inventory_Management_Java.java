import java.util.ArrayList;
import java.util.Scanner;

class Product {
    int id;
    String name;
    int quantity;
    double price;

    Product(int id, String name, int quantity, double price) {
        this.id = id;
        this.name = name;
        this.quantity = quantity;
        this.price = price;
    }
}

public class Inventory_Management_Java {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        ArrayList<Product> inventory = new ArrayList<>();

        int choice;

        do {
            System.out.println("Inventory Management System");
            System.out.println("1. Add Product");
            System.out.println("2. Sell Product");
            System.out.println("3. View Inventory");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");

            choice = input.nextInt();
            input.nextLine();

            if (choice == 1) {

                System.out.print("Enter Product ID: ");
                int id = input.nextInt();
                input.nextLine();

                System.out.print("Enter Product Name: ");
                String name = input.nextLine();

                System.out.print("Enter Quantity: ");
                int quantity = input.nextInt();

                System.out.print("Enter Price per Unit: ");
                double price = input.nextDouble();
                input.nextLine();

                Product product = new Product(
                    id,
                    name,
                    quantity,
                    price
                );

                inventory.add(product);

                System.out.println("Product added successfully!");
            }

            else if (choice == 2) {

                System.out.print("Enter Product ID: ");
                int id = input.nextInt();

                System.out.print("Enter Quantity to Sell: ");
                int quantitySold = input.nextInt();
                input.nextLine();

                boolean found = false;

                for (int i = 0; i < inventory.size(); i++) {

                    Product product = inventory.get(i);

                    if (product.id == id) {

                        found = true;

                        if (quantitySold <= product.quantity) {

                            product.quantity -= quantitySold;

                            System.out.println(
                                "Sale completed successfully!"
                            );

                        } else {

                            System.out.println(
                                "Not enough stock!"
                            );
                        }

                        break;
                    }
                }

                if (!found) {
                    System.out.println("Product not found!");
                }
            }

            else if (choice == 3) {

                double totalValue = 0;

                System.out.println("Inventory Summary");

                if (inventory.isEmpty()) {

                    System.out.println("Inventory is empty.");

                } else {

                    for (Product product : inventory) {

                        double value =
                            product.quantity * product.price;

                        totalValue += value;

                        System.out.println(
                            "\nProduct ID: " + product.id
                        );

                        System.out.println(
                            "Product Name: " + product.name
                        );

                        System.out.println(
                            "Quantity: " + product.quantity
                        );

                        System.out.printf(
                            "Price per Unit: %.2f%n",
                            product.price
                        );

                        System.out.printf(
                            "Stock Value: %.2f%n",
                            value
                        );
                    }

                    System.out.printf(
                        "\nTotal Stock Value: %.2f%n",
                        totalValue
                    );
                }
            }

            else if (choice == 4) {

                System.out.println(
                    "Exiting program..."
                );

            }

            else {

                System.out.println(
                    "Invalid choice! Please enter 1-4."
                );
            }

        } while (choice != 4);

        input.close();
    }
}