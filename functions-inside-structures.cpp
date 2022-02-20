#include<iostream>
using namespace std;



typedef struct SampleStruct
{
    int a;

    SampleStruct()
    {
        cout << "SampleStruct constructor\n";
        a=8;
        b=90;
    }

    SampleStruct(int aVal,int bVal)
    {
        a = aVal;
        b = bVal;
    }

    virtual ~SampleStruct()
    {
        cout << "SampleStruct destructor\n";
    }
private:
    int b;
}S;

class Base : SampleStruct
{
    int f;
public:
    Base()
    {
        cout << "Base constructor\n";
    }

    virtual ~Base()
    {
        cout << "Base destructor\n";
    }
};

// INHERITANCE works for both structures & classes
// Modes of inheritance also work the same way 
// Compile-time polymorphism works with structures.
// Run-time polymorphism does not works with structures.
// //SampleStruct* bPtr = new Derived(); ---> Error

// Structures can inherit from both classes & structures, but no runtime polymorphism here also
// CLASSES vs STRUCTURES (Only 2 differences)
// 1. [CLASS] By default, inheritance mode is private & access specifier in any class is also private
//    [STRUCTURES] By default, inheritance mode is public & access specifier in any struct is also public
// 2. classes can inherit from classes & structures. 
//    structures can inherit from classes & structures.
//    DIFFERENCE is that, whenever there is a struct involved in this inheritance, we do not have any runtime polymorphism,
//    although we do have compile-time polymorphism
//     ONLY "class Derived : Base" will support runtime polymorphism (Base * bPtr = new Derived())

// All other features work in both cases - friend functions, operator overloading, function overloading
struct Derived : private Base
{
    int ab;
    Derived()
    {
        cout << "Derived constructor\n";
    }

    friend ostream& operator<<(ostream& os,S& st)
    {
        os << "Value of a = " << st.a << endl;
        return os;
    }
};



int main()
{
    // S ss(4,5);
    // cout << ss.a << endl;
    // cout << ss;

    // S s1;
    // cout << s1.a << endl;
    // cout << s1;

    {
        Derived d;
        cout << "########################\n";
        //SampleStruct* bPtr = new Derived(); --> Compile-time ERROR
        // Base * bPtr = new Derived(); --> Compile-time ERROR
    }

    {
        
    }
    

}