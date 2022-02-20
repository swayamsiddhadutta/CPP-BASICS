#include<iostream>

extern int globalData;

namespace physics
{
    void doWork()
    {
        std::cout << "Physics work\n";
    }
}

namespace maths
{
    void doWork()
    {
        std::cout << "Maths work\n";
    }
}

//using extern will give assurace
//With "g++ .\namespaces-2.cpp .\namespaces-introduction.cpp", both "extern void my_func(int x);"" & 
// "void my_func(int x);" will work
// However, with "g++ .\namespaces-introduction.cpp"

extern void my_func(int x);

// void my_func(int x) // uncommenting this would lead to multiple definition of my_func (2nd one in namespaces-2.cpp)
// {
//     std::cout << "INTRO::my_func\n" << std::endl;
//     std::cout << "x = " << x << std::endl;
// }

int main()
{
    my_func(4);
    std::cout << "globalData = " << globalData << std::endl;

    physics::doWork();
    maths::doWork();
}