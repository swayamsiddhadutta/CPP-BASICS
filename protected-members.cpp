#include<iostream>
using namespace std;

class Base
{
private:
    int m_private;
protected:
    int m_protected;
public:
    int m_public;
};

class Derived : public Base
{
public:
    Derived()
    {
        // m_private = 0; // NOT ALLOWED
        m_protected = 0; // ALLOWED
        m_public = 0; // ALLOWED
    }
};

class C
{
    Base b;
public:
    C()
    {
        // b.m_private = 0; // NOT ALLOWED
        // b.m_protected = 0; // NOT ALLOWED
        b.m_public = 0; // ALLOWED
    }
};

// Using the protected access specifier is most useful when you (or your team) are going to be the ones deriving from your own classes, 
// and the number of derived classes is reasonable. That way, if you make a change to the implementation of the base class, and updates to 
// the derived classes are necessary as a result, you can make the updates yourself (and have it not take forever, since the number of derived 
// classes is limited).

// Making your members private means the public and derived classes can’t directly make changes to the base class. 
// This is good for insulating the public or derived classes from implementation changes, and for ensuring invariants are maintained properly. 
// However, it also means your class may need a larger public (or protected) interface to support all of the functions that the public or 
// derived classes need for operation, which has its own cost to build, test, and maintain.

// In general, it’s better to make your members private if you can, and only use protected when derived classes are planned and 
// the cost to build and maintain an interface to those private members is too high.

int main()
{
    Derived dObj;
    //dObj.m_private = 0; // NOT ALLOWED
    //dObj.m_protected = 0; // NOT ALLOWED
    dObj.m_public = 0; // ALLOWED
}

