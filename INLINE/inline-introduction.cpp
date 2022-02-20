#include<iostream>

// use of 'inline' before a function means that this code is copied directly to the place it is called
// inline mixes the best of 2 worlds - 
//      (i) functions property of type-checking
//      (ii) the ability to replace code like in preprocessor directives (to increase speed of execution as for small functions,
//           the overhead to make the function call is significant compared to the execution time of the functions)

// We cannot do this with #define MIN(x,y) because there is no type checking there as we have with functions

// However, modern compilers have become intelligent enough to see small functions & make them inline directly
// Sometimes, compilers also ignore the inline keyword if they observe that the function is very long & used frequently, which shall
// increase the executable size without much benefit as for large functions, the cost to make the function call is not high.
inline int min(int x,int y)
{
    return (x <= y) ? x : y;
}

int main()
{
    int minNum1 = min(2,6);
    int minNum2 = min(2,-6);
    std::cout << minNum1 << " " << minNum2 << std::endl;
}