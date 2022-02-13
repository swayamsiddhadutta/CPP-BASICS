#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

struct testStruct
{
    string str; // 32
    set<int> st; // 48

    int a; // 4
};
// sizeof(std::string) = 32 --> ALWAYS irrespective of string length
// SIZE of all containers in terms of sizeof() is decided at compile time.
// The number of elements in the container does not play a role

// AND with relation to struct padding 8 is the maximum size of any data type & 
// therefore, when calculating size, for all these containers, the total size should be a multiple of 8
int main()
{
    cout << "Size of testStruct = " << sizeof(testStruct) << endl; // 88
    cout << "Size of std::string = " << sizeof(string) << endl; // 32
    cout << "Size of set = " << sizeof(set<string>) << endl; // 48
    cout << "Size of map = " << sizeof(map<int,int>) << endl; // 48
    cout << "Size of unordered_map = " << sizeof(unordered_map<int,int>) << endl; // 56
    cout << "Size of queue = " << sizeof(queue<int>) << endl; // 80
    cout << "Size of stack = " << sizeof(stack<int>) << endl; // 80
    cout << "Size of unordered_set = " << sizeof(unordered_set<int>) << endl; // 56
    cout << "Size of priority_queue = " << sizeof(priority_queue<int>) << endl; // 32
    testStruct t;

    // STRING
    cout << "[BEFORE] Size of t = " << sizeof(t) << endl; // 40
    cout << "[BEFORE] Size of t.str = " << sizeof(t.str) << endl; // 32
    t.str.assign("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaassssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    cout << "[AFTER] Size of t = " << sizeof(t) << endl; // 40
    cout << "[AFTER] Size of t.str = " << sizeof(t.str) << endl; // 32
    cout << "t.str.length = " << t.str.length() << endl; // 265

    // SET

}