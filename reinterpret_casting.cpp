// CPP code to illustrate using structure
#include <iostream>
using namespace std;

// https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
// https://stackoverflow.com/questions/2301454/what-defines-an-opaque-type-in-c-and-when-are-they-necessary-and-or-useful
// reinterpret casting is used where there are Opaque structures used inside a 3rd party library, which have to be filled at
// our end
// We can't static_cast opaque pointers, because we don't know the actual data types & structure of a an opaque structure.
// only declaration of opaque is provided to us.
// The definition of the structure is present inside the source files inside 3rd party library which we can't access
// reinterpret_cast does not need to know the actual data type to which it is casting, because it is simply saying the compiler
// to treat the original pointer as a Opaque pointer. Same BITS representation (unlike static_cast where sometimes, the binary 
// representation changes (float --> int))

// creating structure mystruct
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};
 
int main()
{
    mystruct s;
 
    // Assigning values
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;
 
    // data type must be same during casting
    // as that of original
 
    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);
 
    cout << sizeof(s) << endl;
 
    // printing the value currently pointed by *p
    cout << *p << endl;
 
    // incrementing the pointer by 1
    p++;
 
    // printing the next integer value
    cout << *p << endl;
 
    p++;
 
    // we are casting back char * pointed
    // by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);
 
    // printing the character value
    // pointed by (*ch)
    cout << *ch << endl;
 
    ch++;
 
    /* since, (*ch) now points to boolean value,
    so it is required to access the value using
    same type conversion.so, we have used
    data type of *n to be bool. */
 
    bool* n = reinterpret_cast<bool*>(ch);
    cout << *n << endl;
 
    // we can also use this line of code to
    // print the value pointed by (*ch).
    cout << *(reinterpret_cast<bool*>(ch));
 
    return 0;
}