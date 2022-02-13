#include<iostream>
using namespace std;

class Base
{
public:
    void identify()
    {
        cout << "I am Base\n"; 
    }

    friend ostream& operator<<(ostream& os,const Base& b)
    {
        os << "In base\n";
        return os;
    }
};

class Derived : public Base
{
public:
    void identify()
    {
        // WAY TO Call some base function inside derived class function
        Base::identify();
        cout << "I am Derived\n";
    }

    friend ostream& operator<<(ostream& os,const Derived& d)
    {
        os << "In derived\n";
        os << static_cast<const Base&>(d);
        return os;
    }
};

int main()
{
    Derived dObj;
    dObj.identify();

    cout << dObj << endl; // --> This is broken as << (cout,dObj)
}