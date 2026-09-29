/*
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
*/

import java.util.ArrayList;
import java.util.Scanner;

class Item {
    private String name;
    private double price;
    private int quantity;

    public Item(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }
}

public class P1main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String itemName;
        int itemQuantity;
        double itemPrice,
                discount = 1.0, 
                totalPrice = 0.00;
        String receiptFormat = "%-30s%-10s%-10s%10s%n";

        ArrayList<Item> transactionList = new ArrayList<>();

        System.out.println("Enter Item Name, Price, and Quantity.");
        System.out.println("Type 'END' to finish checkout and generate bill.");
        System.out.println();

        while (true) {
            System.out.print("Enter Item Name: ");
            itemName = scanner.nextLine().trim();
            if (itemName.equalsIgnoreCase("END")) {
                break;
            }
            else if (itemName.isEmpty()) {
                System.out.println("Error: Invalid Item Name.\n");
                continue;
            }

            boolean checkDuplicate = false;
            for (Item item : transactionList) {
                if (item.getName().equalsIgnoreCase(itemName)) {
                    checkDuplicate = true;
                    break;
                }
            }
            if (checkDuplicate) {
                System.out.println("Error: Item already exists.");
                continue;
            }

            System.out.printf("Enter Price of %s: ", itemName);
            String priceInput = scanner.nextLine().trim();
            if (priceInput.equalsIgnoreCase("END")) {
                break;
            }
            try {  
                itemPrice = Double.parseDouble(priceInput);
                if (itemPrice < 0) {
                    System.out.println("Error: Invalid Price.\n");
                    continue;
                }
            } catch (NumberFormatException e) {
                System.out.println("Error: Invalid Price.\n");
                continue;
            }

            System.out.printf("Enter Quantity of %s: ", itemName);
            String quantityInput = scanner.nextLine().trim();
            if (quantityInput.equalsIgnoreCase("END")) {
                break;
            }
            try {
                itemQuantity = Integer.parseInt(quantityInput);
                if (itemQuantity <= 0) {
                    System.out.println("Error: Invalid Quantity.\n");
                    continue;
                }
            } catch (NumberFormatException e) {
                System.out.println("Error: Invalid Quantity.\n");
                continue;
            }

            System.out.println();
            transactionList.add(new Item(itemName, itemPrice, itemQuantity));
        }

        System.out.print("Is the customer a member? (Y/N): ");
        String memberInput = scanner.nextLine().trim();

        if (memberInput.equalsIgnoreCase("Y")) {
            discount = 0.9;
        }

        System.out.println("-".repeat(60));
        System.out.println("FINAL BILL");
        System.out.println("-".repeat(60));
        System.out.printf(receiptFormat, "ITEM", "PRICE", "QUANTITY", "SUBTOTAL");

        for (Item item : transactionList) {
            double subTotal = item.getPrice() * item.getQuantity();
            totalPrice += subTotal;
            System.out.printf(receiptFormat, item.getName(), String.format("₱%.2f", item.getPrice()), item.getQuantity(), String.format("₱%.2f", subTotal));
        }
        System.out.println("-".repeat(60));

        if (discount < 1.0) {
            System.out.printf(receiptFormat, "DISCOUNT (10%)", "", "", String.format("₱-%.2f", totalPrice * 0.1));
        }

        System.out.printf(receiptFormat, "TOTAL", "", "", String.format("₱%.2f", totalPrice * discount));
    }
}