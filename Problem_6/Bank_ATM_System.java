import java.util.Scanner;

public class ATMSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] accNumbers = {"1001", "1002", "1003"};
        String[] passwords = {"pass123", "secret456", "atm789"};
        double[] balances = {5000.00, 12000.50, 300.00};

        char choice = 'y';

        while (choice == 'y' || choice == 'Y') {
            System.out.println("\n=== BANK ATM WITHDRAWAL SYSTEM ===");
            System.out.print("Enter Account Number: ");
            String inputAcc = scanner.next();
            System.out.print("Enter Password: ");
            String inputPass = scanner.next();

            int foundIndex = -1;

            if (inputAcc.equals(accNumbers[0]) && inputPass.equals(passwords[0])) {
                foundIndex = 0;
            } else if (inputAcc.equals(accNumbers[1]) && inputPass.equals(passwords[1])) {
                foundIndex = 1;
            } else if (inputAcc.equals(accNumbers[2]) && inputPass.equals(passwords[2])) {
                foundIndex = 2;
            }

            if (foundIndex != -1) {
                System.out.println("\nLogin Successful!");
                System.out.println("\nCurrent Balance: $" + balances[foundIndex]);
                System.out.print("Enter Withdrawal Amount: $");
                double withdrawAmount = scanner.nextDouble();

                if (withdrawAmount <= 0) {
                    System.out.println("Invalid withdrawal amount.");
                } else if (withdrawAmount > balances[foundIndex]) {
                    System.out.println("\nTransaction Failed: Insufficient balance!");
                } else {
                    balances[foundIndex] = balances[foundIndex] - withdrawAmount;
                    System.out.println("\nTransaction Successful!");
                    System.out.println("\nRemaining Balance: $" + balances[foundIndex]);
                }
            } else {
                System.out.println("\nError: Invalid Account Number or Password!");
            }

            System.out.print("\nDo you want to perform another transaction? (y/n): ");
            choice = scanner.next().charAt(0);
        }

        System.out.println("\nThank you for using our ATM. Goodbye!");
        scanner.close();
    }
}