#include<iostream>
// using namesapce std; <--- Should avoid this in big projects because names may collide very easily

// making a global variable static means that it can only be used in current file.
// it cannot be made extern from another cpp file. g++ compilation will move till before the linking stage, 
// but, it will fail at the linking stage (g++ .\namespaces-2.cpp .\namespaces-introduction.cpp)
// static int globalData = 89;

// QUALIFIED and UNQUALIFIED NAMES
// :: foo // identifier foo is qualified by global namespace
// std::cout // identifier cout is qualified by namesapce std
// class C;
// C::s_member; //s_member is qualified by class C
// obj.x; // x is qualified by object obj
//
int globalData = 89;
void my_func(int x)
{
    std::cout << "2::my_func\n" << std::endl;
    std::cout << "x = " << x << std::endl;
}