#include <bits/stdc++.h>
using namespace std;

class Employee
{
protected:
    string name;
    int employeeId;
    int baseSalary;

public:
    Employee(const string &name, int employeeId, int baseSalary)
        : name(name), employeeId(employeeId), baseSalary(baseSalary) {}

    virtual int calculateSalary() const
    {
        return baseSalary;
    }

    void displayInfo() const
    {
        cout << "Employee ID: " << employeeId << "\n";
        cout << "Name: " << name << "\n";
        cout << "Base Salary: $" << baseSalary << "\n";
        cout << "Calculated Salary: $" << calculateSalary() << "\n";
    }
};

class Manager : public Employee
{
private:
    int bonus;

public:
    Manager(const string &name, int employeeId, int baseSalary, int bonus)
        : Employee(name, employeeId, baseSalary), bonus(bonus) {}

    int calculateSalary() const override
    {
        return baseSalary + bonus;
    }
};

class Developer : public Employee
{
private:
    int overtimePay;

public:
    Developer(const string &name, int employeeId, int baseSalary, int overtimePay)
        : Employee(name, employeeId, baseSalary), overtimePay(overtimePay) {}

    int calculateSalary() const override
    {
        return baseSalary + overtimePay;
    }
};

class Designer : public Employee
{
private:
    int projectBonus;

public:
    Designer(const string &name, int employeeId, int baseSalary, int projectBonus)
        : Employee(name, employeeId, baseSalary), projectBonus(projectBonus) {}

    int calculateSalary() const override
    {
        return baseSalary + projectBonus;
    }
};

int main()
{

    string emp_name;
    int emp_id, emp_base_salary;
    cin >> emp_name >> emp_id >> emp_base_salary;

    Employee emp1(emp_name, emp_id, emp_base_salary);

    int bonus;
    cin >> emp_name >> emp_id >> emp_base_salary >> bonus;
    Manager manager(emp_name, emp_id, emp_base_salary, bonus);

    cin >> emp_name >> emp_id >> emp_base_salary >> bonus;
    Developer developer(emp_name, emp_id, emp_base_salary, bonus);

    cin >> emp_name >> emp_id >> emp_base_salary >> bonus;
    Designer designer(emp_name, emp_id, emp_base_salary, bonus);

    cout << "Employee Information:\n";
    emp1.displayInfo();

    cout << "\nManager Information:\n";
    manager.displayInfo();

    cout << "\nDeveloper Information:\n";
    developer.displayInfo();

    cout << "\nDesigner Information:\n";
    designer.displayInfo();

    return 0;
}
