class Employee {
    String ID;
    String name;
    int hourlyRate;
    int hoursWorked;
    double grossPay;
    double tax;
    double netPay;

    public Employee(String ID, String name, int hourlyRate, int hoursWorked) {
        this.ID = ID;
        this.name = name;
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
        this.grossPay = this.getGrossPay();
        this.tax = this.getTax();
        this.netPay = this.getNetPay();
    }

    public double getGrossPay() {
        grossPay = this.hourlyRate * this.hoursWorked;
        return grossPay;
    }

    public double getTax() {
        tax = this.grossPay * 0.10;
        return tax;
    }

    public double getNetPay() {
        netPay = this.grossPay - this.tax;
        return netPay;
    }

    public void getSummary() {
        System.out.println("Payroll Summary");
        System.out.println("==============================");
        System.out.println("Employee ID: " + this.ID);
        System.out.println("Employee Name: " + this.name);
        System.out.println("Net Pay: " + this.netPay);
        System.out.println("\n");
    }

    public static void main(String[] args) {
        Employee employee_1 = new Employee("2006192375", "John", 40, 500);
        Employee employee_2 = new Employee("2006353423", "Paul", 38, 600);
        Employee employee_3 = new Employee("2006475334", "George", 44, 550);
        Employee employee_4 = new Employee("2006453678", "Ringo", 50, 700);

        employee_1.getSummary();
        employee_2.getSummary();
        employee_3.getSummary();
        employee_4.getSummary();
    }
}