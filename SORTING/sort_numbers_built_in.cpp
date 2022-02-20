#include<iostream>
#include<vector>
#include<algorithm>

struct Interval
{
    int start,end;
};

bool compareIntervals(const Interval& i1,const Interval& i2)
{
    return i1.start <= i2.start;
}

void print(std::vector<int>& vec)
{
    for(auto it: vec)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

void print(Interval arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout << "{ " << arr[i].start  << ", " << arr[i].end << " }, ";
    }
    std::cout << "\n";
}

// INTERNALLY, sort uses something called the IntroSort algorithm
// IntroSort Algorithm --> MIX of QuickSort, HeapSort & InsertionSort

int main()
{
    // 1st way to initialize vector
    std::vector<int> vec{2,3,4,5,6};
    
    int arr[] = {1,10,189,45,34};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::sort(vec.begin(),vec.end()); // ASCENDING order
    print(vec);

    std::sort(vec.begin(),vec.end(), std::greater<int>()); // Descending Order
    print(vec);

    std::cout << vec[0] << std::endl;
    std::sort(arr, arr + n,std::greater<int>());
    // 2nd way to initialize vector (from existing array)
    std::vector<int> vec2(arr,arr+n);
    print(vec2);

    Interval vecIntervals[] = {{1,6},{1,5},{0,2},{4,10}};
    int numIntervals = sizeof(vecIntervals) / sizeof(vecIntervals[0]);
    
    // On arrays of user-defined data type, compare function has to be provided
    std::sort(vecIntervals,vecIntervals + numIntervals,compareIntervals); 
    print(vecIntervals,numIntervals);

    // IN-PLACE Custom comparator function usage --> use of '[]' (custsom C++14 polymorphic lambda)
    std::sort(vecIntervals,vecIntervals + numIntervals,[] (Interval& i1,Interval& i2) {
        return i1.start < i2.start;
    }); 
    print(vecIntervals,numIntervals);
}