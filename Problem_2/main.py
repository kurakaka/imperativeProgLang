class Employee():
    """Model of an employee"""
    def __init__(self, ID, name, hourlyRate, hoursWorked):
        self.ID = ID
        self.name = name
        self.hourlyRate = hourlyRate
        self.hoursWorked = hoursWorked
        self.grossPay = self.getGrossPay()
        self.tax = self.getTax()
        self.netPay = self.getNetPay()


    def getGrossPay(self):
        """Compute the gross pay of employee"""
        grossPay = self.hourlyRate * self.hoursWorked
        return grossPay


    def getTax(self):
        tax = self.grossPay * 0.10
        return tax


    def getNetPay(self):
        netPay = self.grossPay - self.tax
        return netPay

    def getSummary(self):
        print("Payroll Summary")
        print("=="*15)
        print("Employee ID:", self.ID)
        print("Employee Name:", self.name)
        print("Net Pay:", self.netPay)
        print('\n')

if __name__ == '__main__':
    # Allow multiple employees
    employee_1 = Employee(ID='2006192375', name='John', hoursWorked=40, hourlyRate=500)
    employee_2 = Employee(ID='2006353423', name='Paul', hoursWorked=38, hourlyRate=600)
    employee_3 = Employee(ID='2006475334', name='George', hoursWorked=44, hourlyRate=550)
    employee_4 = Employee(ID='2006453678', name='Ringo', hoursWorked=50, hourlyRate=700)

    employee_1.getSummary()
    employee_2.getSummary()
    employee_3.getSummary()
    employee_4.getSummary()
