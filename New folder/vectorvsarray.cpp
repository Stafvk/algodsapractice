#include <iostream>
#include <vector>
#include <stdio.h>
// Stdio. is a C header that lets us use printf and scanf

//using array standard library
#include<array>
using namespace std;

int main()
{
    int arr[10] = {0};
    // if we write int arr[10]={};
    // this automatically assigns all the values to Zero and if we are writing
    // int arr[10]={1}, then the first element is 1 rest it it zero

    int sampleArray[] = {1, 2, 3, 4, 5};


    //initialising Vector
    vector<int> newVector={5};
    cout<<"\nVector elements are:";
    for(int num:newVector){
        cout<<" "<<num;
    }
    // iterating using Range, this directly access the element
    cout<<"\nArray elements are:";
    for (int num : arr)
    {
        cout << " " << num;
    }
    int n = sizeof(sampleArray);
    // the output you get is 20 because each integer takes 4 bytes and there are 5 integers. The alternative is using this
    int length = sizeof(sampleArray) / sizeof(sampleArray[0]);
    // The output is 5

    // Another alternative is using the Array library std::array
array <int,5> newArray={5};
cout<<"Array items using array library";
for(int num:newArray){
    cout<<" "<<num;
}
int newLength=size(newArray);
  
    cout << "length of the array:" << length;
    cout << "length of the new array:" << newLength;

/* Using For Loop */
cout<<"\n Elements using indexing for loop";
for(int i=0;i<length;i++){
    cout<<sampleArray[i];
}

/*Using Iterators*/
//Iterators are supported in Vectors

//Use of Iterators in array
    int arrr[] = {1, 2, 3, 4, 5};
    
    // Using pointers as iterators
cout<<"\n Elements using Iterator";
//for built in array like "arrr" we cannot use iterators but we can use pointers as iterators
    for (int* it = arrr; it != arrr + 5; ++it) {
        std::cout << *it << " ";
    }
    
    return 0;

}