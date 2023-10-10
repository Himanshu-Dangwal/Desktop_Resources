#include <bits/stdc++.h>
using namespace std;

class Parent
{
protected:
    string name;

public:
    Parent(string name)
    {
        this->name = name;
    }
    void reverseName()
    {
        string reversed = this->name;
        reverse(reversed.begin(), reversed.end());
        cout << reversed << endl;
    }
};

class Child : public Parent
{
public:
    Child(string name) : Parent(name) {}
};

int main()
{
    string name;
    cin >> name;
    Child child(name);
    child.reverseName();
}