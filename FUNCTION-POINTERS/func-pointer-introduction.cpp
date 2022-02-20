#include<iostream>

// funcPtr is a pointer to a function that takes no arguments and returns an integer
// funcPtr can point to any function that matches the above type
// Parentheses are necessary for precedence reasons as int* funcPtr() would denote a function with no arguments & that returns
// an integer pointer

int (*funcPtr)(); // --> non-const function pointer
//int (*const funcPtrConst)(); // --> const function pointer

int foo()
{
    std::cout << "foo called\n";
    return 5;
}

int goo()
{
    std::cout << "goo called\n";
    return 6;
}

char func(int x,const std::string& str)
{
    std::cout << "func:: x = " << x << std::endl;
    std::cout << "func:: str = " << str << std::endl;
    return 'A';
}

double fun1(double x,int y)
{
    std::cout << "fun1:: x = " << x << std::endl;
    std::cout << "fun1:: y = " << y << std::endl;
    return x + 2;
}

int main()
{
    // [1] without any arguments
    funcPtr = &foo;
    int ret = (*funcPtr)();
    std::cout << "retVal = " << ret << "\n";

    funcPtr = &goo;
    ret = (*funcPtr)();
    std::cout << "retVal = " << ret << "\n";

    std::cout << (void *)funcPtr << std::endl; // --> FUNCTION POINTER  

    // [2] with arguments
    char (*charFuncPtr)(int,const std::string&);
    charFuncPtr = &func; 
    char retChar = (*charFuncPtr)(5,"fggh");
    std::cout << "retVal = " << retChar << "\n";

    // [3] direct initialization at the time of declaration
    double (*dblFuncPtr)(double,int) { fun1 };
    double retDbl = dblFuncPtr(4.5,7);

    std::cout << "retDbl = " << retDbl << "\n";
}