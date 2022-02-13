#include<iostream>
using namespace std;

class A
{
public:
    void fun1()
    {
        cout << "A :: fun1\n"; 
    }
};

class B : public A
{
public:
    void fun1()
    {
        cout << "B :: fun1\n"; 
    }
};

class C : public B
{
public:
    // void fun1()
    // {
    //     cout << "C :: fun1\n"; 
    // }

    // When a member function is called with a derived class object, the compiler first looks to see if that member exists in the derived class. 
    // If not, it begins walking up the inheritance chain (C --> B --> A) and checking whether the member has been defined in any of the parent classes. It uses 
    // the first one it finds.
};

int main()
{
    C cObj;
    cObj.fun1();

    // B :: fun1 (not A :: fun1)
}