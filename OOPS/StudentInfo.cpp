#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;

public:
    void setRollNo(int roll)
    {
        this->rollNo = roll;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void showDetails()
    {
        cout << this->rollNo << " " << this->name << " " << this->age;
    }
};

int main()
{
    Student s;
    int roll, age;
    string name;

    cin >> roll >> name >> age;

    s.setRollNo(roll);
    s.setName(name);
    s.setAge(age);

    s.showDetails();
    return 0;
}