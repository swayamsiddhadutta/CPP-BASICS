#include<iostream>
using namespace std;

class Base
{
public:
    int aa;
    Base(int a=0) : aa(a)
    {
        cout << "Parameterized constructor - [ Base ]\n";
    }
};

class C
{
    int m_c;
public:
    C()
    {
        cout << "Default constructor - [ C ]\n";
    }

    C(const C &c)
    {
        cout << "Copy constructor - [ C ]\n";
        m_c = c.m_c;
    }
};

class Derived : public Base
{
public:
    int b;
    C cObj;
    // COMPILE ERROR when we try to initialize Base class member in Derived class initializer list.
    // C++ prevents classes from initializing inherited member variables in the member initializer list of a constructor
    // The value of a member variable can only be set in a member initializer list of a constructor belonging to the same class as the variable.
    
    // Irrespective of the order of initialization in initializer list, Base class constructor is always called 1st
    Derived(int a,int b,C &rObj) : cObj(rObj), Base(a), b(b)//,aa(a) 
    {
        // aa =a; // THIS can be done, but it is not good practice. And also this cannot be done for const & reference variables
    }
};

int main()
{
    C cObj1;
    Derived d(2,3,cObj1);

    // Default constructor - [ C ]
    // Parameterized constructor - [ Base ]
    // Copy constructor - [ C ]
}