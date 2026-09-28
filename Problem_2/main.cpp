#include <iostream>
#include <string>

using namespace std;

class Employee {   
  private:
    string ID;  
    string name;  
    int hourlyRate;   
    int hoursWorked;   
    double grossPay;
    double tax;
    double netPay;  

  public:        
    double getGrossPay() {  
      grossPay = hourlyRate * hoursWorked;
      return grossPay;
    }

    double getTax() {  
      tax = grossPay * 0.10;
      return tax;
    }

    double getNetPay() { 
      netPay = grossPay - tax;
      return netPay;
    }

    void getSummary() { 
      cout << "Payroll Summary\n";
      cout << "==============================\n";
      cout << "Employee ID: " << ID << "\n";
      cout << "Employee Name: " << name << "\n";
      cout << "Net Pay: " << netPay << "\n";
      cout << '\n';
    }

    Employee(string ID, string name, int hourlyRate, int hoursWorked) { 
      this->ID = ID;
      this->name = name;
      this->hourlyRate = hourlyRate;
      this->hoursWorked = hoursWorked;

      this->grossPay = getGrossPay();
      this->tax = getTax();
      this->netPay = getNetPay();
    }
};

int main() {

  Employee employee_1{"2006192375", "John", 40, 500};  
  Employee employee_2{"2006353423", "Paul", 38, 600};  
  Employee employee_3{"2006475334", "George", 44, 550};  
  Employee employee_4{"2006453678", "Ringo", 50, 700};  
 
  employee_1.getSummary();
  employee_2.getSummary();
  employee_3.getSummary();
  employee_4.getSummary();

  return 0;
}







