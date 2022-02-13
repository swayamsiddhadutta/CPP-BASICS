#include<iostream>
using namespace std;

enum Department {
    PLATFORM_SW = 0,
    APPLICATION_SW,
    CLOUD,
    DATA_INTELLIGENCE,
    NO_DEPARTMENT
};

class Person 
{
// PRIVATE members are accessible only by 
//         (a) the member functions inside the class itself & 
//         (b) friend functions
private: 
    int m_age;
    static int m_numPersons;

// PROTECTED members are accessible only by
//         (a) the member functions inside the class itself & 
//         (b) friend functions
//         (c) member functions of any of it's derived classes 
protected:
    string m_name;

// PUBLIC members are accessible everywhere
public:
   
    // Person()
    // {
    //     cout << "Default Person constructor\n";
    //     m_numPersons++; 
    // }

    // Person() & Person(string name="",int age=0) cannot be both present in a class definition because
    // both are exactly the same
    Person(string name="",int age=0) : m_name(name), m_age(age)
    {
        cout << "Person constructor\n"; 
        m_numPersons++;
    }

    // Type qualifiers like const are not allowed on static member functions
    // static int getNumPersons() const { -----> ERROR
    // REASON: Type qualifiers like const are used after member functions to ensure that an object's member variables are not changed
    //         Since, static functions are accessed using the scope resolution operator, it does not make sense to have const static member function
    //         Therefore, there is compile-time error here.
    // Also type qualifiers like const cannot be used for non-member functions either global or static
    static int getNumPersons() {
        // STATIC member functions cannot access non-static member functions & non-static member variables because it does not make sense
        // for a common class function to access functions & variables which are related to a specifc object
        return m_numPersons;
    }

    const string& getName() const {
        return m_name;
    }

    int getAge() const {
        return m_age;
    }
    
    // BASE class (Person) destructor should be made virtual so that all child classes' destructor is also called when 
    // implementing runtime Polymorphism using Base * bPtr = new Derived();
    virtual ~Person()
    {
        cout << "Person destructor\n"; 
    }
};

class Employee : public Person
{
    int m_empID;
    Department m_dept;
public:
    Employee(int employeeID = 0, Department dept = NO_DEPARTMENT) :  m_empID(employeeID), m_dept(dept)
    {
        cout << "Employee constructor\n";
        cout << "Total Persons (in EMPLOYEE class constructor) : " << m_name;
        // ONLY PROTECTED & PUBLIC members of parent class can be accessed in child class directly
    } 

    int getEmpID() const {
        return m_empID;
    }

    Department getDept() const {
        return m_dept;
    }

    ~Employee()
    {
        cout << "Employee destructor\n";
    }
};

// private/public static variable needs to be intialized globally, but, in case of multiple source & header files,
// We must declare in header file
// And initialize in source file which includes the header file, so as to avoid compiler error of multiple initialization
int Person::m_numPersons = 0;
static const int ty = 0; 
int main()
{
    Employee raju(1,PLATFORM_SW);
    cout << "Name of raju: " << raju.getName() << endl;
    cout << "Department of raju: " << raju.getDept() << endl;

    const int totalPersons = Person::getNumPersons();
    //totalPersons++;
    cout << "TOTAL Persons: " << totalPersons << endl;
}