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
    }
    A& operator= (const A &a)
    {
        if(this == &a) return *this;
        cout << "Assignment Operator - [ A ] \n";
        m_a = a.m_a; // This WORKS, even though we are accessing private variable of different object.
                     // It works because the private & public access specifier is for other entities like other classes, derived classes,
                     // main() or any other global function
                     // For maintainers of a class it does not mean anything
                     // Basically access specifiers / permissions are for OBJECT-level, not for CLASS-level
        return *this;
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

    B(A &a) // IMPORTANT: Should always take values by reference if we wish to take the same object & avoid an additional object of A and an  
    {       // additional copy constructor call of A
        m_aObj = a;
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
        // Default constructor - [ A ] 
        // Assignment Operator - [ A ] 
        // Parameterized constructor - [ B ] 
        // Destructor - [ B ]
        // Destructor - [ A ] --> For COMPOSITION case, the inner class object (m_aObj) (or the class which is composed in another class) is 
        //                        destroyed after the destructor call of outer class (bObj)
    }    
    // Destructor - [ A ]
}