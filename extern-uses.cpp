#include<iostream>


extern "C" int addNums(int a,int b)
{
    return a + b;
}

extern "C" int addNums(int a,int b,int c)
{
    return a + b + c;
}




int main()
{
    int SUM = addNums(5,6);
    int SUM2 = addNums(5,6,45);

    std::cout << SUM << " " << SUM2 << std::endl;
}