#include<iostream>
#include<string.h>
using namespace std;

 // FUNCTION overloading cannot be done only based on return type.
 // Something other than the return type has to be different - either, number of arguments OR order of arguments OR data type of arguments
 // OR else it causes compile-time error

int func(int x)
{
    return x;
}

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
    int a = func(10);
    int b = func(10.10f);
    int c = func("HELLO");    
    //char d = 
    cout << a << " " << b << " " << c << endl;
}