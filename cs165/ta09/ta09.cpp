#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Employee
{
protected:
   string name;

public:
   string getName() const { return name; }
   void setName(string name) { this->name = name; }

   virtual void display()
   {
      cout << getName() << endl;
   }

   virtual int getPayCheck() = 0;
};

class HourlyEmployee : public Employee
{
private:
   int hourlyWage;
   int hours;

public:
   HourlyEmployee(string name, int hourlyWage, int hours)
   {
      setName(name);
      setHourlyWage(hourlyWage);
      setHours(hours);
   }
   int getHourlyWage() const { return hourlyWage; }
   void setHourlyWage(int hourlyWage) { this->hourlyWage = hourlyWage; }
   int getHours() const { return hours; }
   void setHours(float hours) { this->hours = hours; }

   void display()
   {
      cout << getName() << " - $" << getHourlyWage() << "/hour" << endl;
   }

   int getPayCheck()
   {
      return getHours() * getHourlyWage();
   }
};

class SalaryEmployee : public Employee
{
private:
   int salary;

public:
   SalaryEmployee(string name, int salary)
   {
      setName(name);
      setSalary(salary);
   }
   int getSalary() const { return salary; }
   void setSalary(int salary) { this->salary = salary; }

   void display()
   {
      cout << getName() << " - $" << getSalary() << "/year" << endl;
   }

   int getPayCheck()
   {
      return getSalary() / 24;
   }
};

#define MAX 3

int main()
{
   Employee* employees[MAX];
   char choice = 'g';
   string nameTemp = "";
   int wageTemp = 0;
   float hoursWorked = 0;

   for (int i = 0; i < 3; i++)
   {
      do{
         cout << "Enter employee type (h/s): ";
         cin >> choice;
         choice = tolower(choice);
      }
      while (choice != 'h' && choice != 's');

      cout << "Error!Please retype Employee name: ";
      cin >> nameTemp;

      switch (choice)
      {
         case 'h': // hourly employees
            cout << "Enter hourly wage: ";
            cin >> wageTemp;
            cout << "Enter hours worked: ";
            cin >> hoursWorked;

            employees[i] = new HourlyEmployee(nameTemp, wageTemp, hoursWorked);

            break;
         case 's': // salary employees
            cout << "Enter the salary: ";
            cin >> wageTemp;

            employees[i] = new SalaryEmployee(nameTemp, wageTemp);

            break;
         default: // something is wrong
            cout << "why did we get this?\n";
      }

   }

   for (int i = 0; i < MAX; i++)
   {
      employees[i]->display();
      cout << "Pay period: $" << employees[i]->getPayCheck() << endl;
   }

   for (int i = 0; i < MAX; i++)
   {
      delete employees[i];
      employees[i] = NULL;
   }
   return 0;
}