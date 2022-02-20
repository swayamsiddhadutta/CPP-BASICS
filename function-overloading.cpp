#include<iostream>
#include<string.h>
using namespace std;

 // FUNCTION overloading cannot be done only based on return type.
 // Something other than the return type has to be different - either, number of arguments OR order of arguments OR data type of arguments
 // OR else it causes compile-time error

// DEFAULT VALUE should always be filled from the last parameter (rightmost) in order for compiler to determine which function to call 
//int func(int x=9,int y,int z=90) --> WRONG when we call "int a =func(5);"

int func(int x,int y=9,int z=90) // --> CORRECT when we call "int a =func(5);"
{
    return x;
}

// The below code will cause compile error as there will be 2 definitions of int func()
// int func()
// {
//     return 4;
// }

string func(int d,int f)
{
    return "54646fedfv";
}

int func(float x)
{
    return (int)x + 89;
}

int func(string x)
{
    return x.length();
}

//int func()
int main()
{
    //int s = func(2,3);
    int a = func(10);
    int b = func(10.10f);
    int c = func("HELLO");    
    //char d = 
    cout << a << " " << b << " " << c << endl;
}