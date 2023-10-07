#include <bits/stdc++.h>
using namespace std;

class Parent
{

protected:
    int id_protected;
};

class Child : public Parent
{
public:
    void setId(int id)
    {
        id_protected = id;
    }

    void displayId()
    {
        cout << "id_protected is: " << id_protected << endl;
    }
};

int main()
{

    Child obj1;

    int id;
    cin >> id;

    obj1.setId(id);
    obj1.displayId();
    return 0;
}
