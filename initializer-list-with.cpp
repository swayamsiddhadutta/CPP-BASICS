#include<iostream>
using namespace std;

class A
{
    int m_a;
public:
    A()
    {
        cout << "Default constructor - [ A ] \n";
        m_a = 10;
    }
    A(const A &a)
    {
        cout << "Copy constructor - [ A ] \n";
        m_a = a.m_a;
        // COPY constructor looks the same as a default constructor, only it takes 1 const reference of same class (A) in it's input
    }
    A& operator= (const A &a)
    {
        if(this == &a) return *this;
        cout << "Assignment Operator - [ A ] \n";
        m_a = a.m_a;
        return *this; // ASSIGNMENT operator should return reference to handle the case of A aObj; aObj = aObj2 = aObj3;
    }

    void setA(int aVal)
    {
        m_a = aVal;
    }

    int getA() const
    {
        return m_a;
    }

    ~A()
    {
        cout << "Destructor - [ A ] \n";
    }
};

class B
{
    A m_aObj;
public:
    B()
    {
        cout << "Default constructor - [ B ] \n";
    }

    // IMPORTANT: Should always take objects by reference in B(A &a) (not B(A a)) if we wish to take the same object
    // & avoid an additional object of A and an additional copy constructor call of A
    B(A &a) : m_aObj(a) 
    {                   
        cout << "Parameterized constructor - [ B ] \n";
    }

    int getAVal() const
    {
        return m_aObj.getA();
    }

    ~B()
    {
        cout << "Destructor - [ B ] \n";
    }
};

int main()
{
    A aObj;
    // Default constructor - [ A ] 
    {
        B bObj(aObj);
        // Copy constructor - [ A ] 
        // Parameterized constructor - [ B ]
        // Destructor - [ B ] 
        // Destructor - [ A ] --> EXPLAINED in initializer-list-without.cpp
    }
    // Destructor - [ A ] 

    // As compared to initializer-list-without.cpp, here we are saving 1 extra call while creating B as here we have:
    // 1. Copy Constructor - A
    // whereas in initializer-list-without.cpp, we have
    // 1. Constructor - A
    // 2. Assignment Operator - A

    // THIS extra call is very useful when initializing objects with large number of member variables
    // Therefore, using initializer list is very good for improve performance
}