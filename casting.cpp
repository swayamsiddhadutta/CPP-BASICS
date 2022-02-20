#include<iostream>
#include<iomanip>
#include<typeinfo> // for typeid

// Some type conversions are always safe to make (such as int to double), whereas others may result in the value being 
// changed during conversion (such as double to int). Unsafe implicit conversions will typically either generate a compiler
// warning, or (in the case of brace initialization) an error.
// This is one of the primary reasons brace initialization is the preferred initialization form. 
// Brace initialization will ensure we don’t try to initialize a variable with a initializer that will lose value when it is 
// implicitly type converted.

void printInt(int x)
{
    std::cout << x << std::endl;
}

int main()
{
    printInt(2);

    //int i{3.5}; // COMPILER ERROR --> Brace initialization does not allow narrowing conversions
    int j = 3.5; // NO error --> Copy initialization allows narrowing conversions

    short s{ -3 }; // there is no short literal suffix, so we'll use a variable for this one
    std::cout << "Size of short = " << sizeof(short) << std::endl;
    std::cout << "Size of bool = " << sizeof(bool) << std::endl;
    printInt(s); // numeric promotion of short to int

    unsigned int d = s;
    std::cout << d << std::endl;
    printInt(d);

    printInt('a'); // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int


    // float precision upto 7 decimal points
    // double precision upto 15 decimal points
    float f = 0.123456789; // double value 0.123456789 has 9 significant digits, but float can only support about 7
    double dbl = 0.123456789; 
    std::cout << std::setprecision(9) << f << '\n'; // std::setprecision defined in iomanip header
    std::cout << f << '\n';
    std::cout << std::setprecision(9) << dbl << '\n'; // std::setprecision defined in iomanip header


    // ARITHMETIC conversions come into play when the type of the final value is not defined already.
    // EXAMPLE: IN std::cout, the arithmetic conversions are used
    // In INt c = 2 + 4.5; --> Since return type int is guaranteed, 4.5 is converted to 4 & then, added
    int it{ 2 };
    double dt{ 3.5 };
    std::cout << typeid(it + dt).name() << ' ' << it + dt << '\n'; // show us the type of i + d

    int c = 2 + 4.5;
    std::cout << typeid(c).name() << ' ' << c << '\n'; // show us the type of c
    
    float cf = 2 + 4.5;
    std::cout << typeid(cf).name() << ' ' << cf << '\n'; // show us the type of cf

    std::cout << typeid(cf + c).name() << ' ' << cf + c << '\n'; // show us the type of cf
    return 0;
}
