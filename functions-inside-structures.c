// DIFFERENCE between g++ & gcc
// 1. g++ runs .c & .cpp files as C++ source code
// 2. gcc runs a .c file as a C source code & .cpp file as a C++ source code

// THIS file will run with g++
// This file with a .cpp extension will wotk with gcc
// But as C source code, this will give compile error
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

