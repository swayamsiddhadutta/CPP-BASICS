#include<iostream>
using namespace std;

// NAMING CONVENTION:
// 1. Classes, structs & typedefs --> CamelCase starting with UpperCase (No underscores in class name)
// 2. functions, variables --> CamelCase starting with lowercase
// Pointer variables should be prepended with ‘p’ and place the asterisk ‘*’ close to the variable name instead of pointer type.
// Reference variables should be prepended with ‘r’. This helps to differentiate between the method returning a modifiable object
// and the same method returning a non-modifiable object.
// The private attribute name in class should be prepended with the character ‘m’.
// Static variables should be prepended with ‘s’.
// The global constants should be all capital letters separated with ‘_’.
class TestClass
{
    int &m_rAge;
    int *m_pAge; // NOT int* pName (Syntactically correct, but wrong as per naming conventions)
    const int m_p;
public:
    
    TestClass(int p,int &rAge) : m_p(p), m_rAge(rAge)
    {
        // Uses of Initializer List
        // [1] Initializing const variable of class (because initializer list initializes class variables while construtor assigns value)
        //     Even if we do not explicitly call the initializer list, the compiler initializes all members except const & references
        // [2] Initializing reference variables
        cout << "Parameterized TestClass Constructor\n";
        
    }

    int getAge() const 
    {
        return m_rAge;
    }

    ~TestClass()
    {
        cout << "testClass Destructor\n";
    }
};

class B
{
    TestClass t; // COMPOSITION (B has a TestClass)
    int m_Test;
public:
    // Uses of Initializer List
    B(int m, int m_Test) : t(45,m), m_Test(m_Test)
    {
        // [3] For initialization of member objects which do not have default constructor
        // [4] For calling the parameterized Base constructor (Iniitializer list is the only way to do this)
        // [5] When constructor’s parameter name is same as data member (Although it can also be done using this pointer)
        // [6] For performance reasons: https://www.geeksforgeeks.org/output-of-c-program/ 
        //     (Check initializer-list-with.cpp VS initializer-list-without.cpp for understanding this)
        cout << "Parameterized constructor - B\n";
    }
};

int main()
{
    // (a) When we create parameterized constructors without default values for each of the parameters, 
    // then our default constructor does not exist anymore, therefore, it will be error if we call it as below 
    // TestClass tObj; --> COMPILE ERROR --> No default constructor
    // (b) When we provide some default values to all parameters of a paraeterized constructor, then it acts as a no parameter / default constructor
    // (c) Basically, if we write a parameterized constructor for a class (with default value missing), then we have to write the 
    // non-parameterized constructor explicitly for making object without any parameter in constructor 
    int rAge = 36;
    TestClass tObj(5,rAge);

    cout << tObj.getAge() << endl;
    rAge = 30;
    cout << tObj.getAge() << endl;

    B bObj(6,5);
    // B bObj; // error as there is no default constructor anymore.

}