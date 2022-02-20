// DIFFERENCE between g++ & gcc
// 1. g++ runs .c & .cpp files as C++ source code
// 2. 
#include<stdio.h>

struct SampleStruct
{   
    int s;
    void func() // <-- No functions allowed inside structures in C
    {
        printf("func called\n");
    }
};
typedef struct SampleStruct S;

int main()
{
    S ss;
    ss.func();
}

