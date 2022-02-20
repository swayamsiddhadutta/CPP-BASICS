#include<iostream>
#include<time.h>
#include<unistd.h>
#define MOD 1e9 + 7
// a constexpre is evaluated at compile time, whihc ,in turn saves up on execution time
// C++11 allows only 1 statement (which is a return statement) inside a constexpr function
// C++14 allows more than 1 statement
// constexpr can refer to only constant global vatiables
// constexpr function can call only other constexpr function

// Have to use const in the value which is returning from a constexpr function in order to evaluate it at compile time

constexpr int fib(int n)
{
    return (n>=2) ? fib(n-1) + fib(n-2) : n;  
}

constexpr int fact(int n)
{
    return (n>=1) ? n  * fact(n-1) : 1;  
}

int main()
{
    double time_spent = 0.0;

    clock_t begin = clock();
    int val = fact(50);
    sleep(3);
    clock_t end = clock();
    
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    std::cout << "fact(100) = " << val << std::endl;
}