//array initializing, display data and find max in array
#include <iostream>
using namespace std;
int main()
{
    // declaring an array

    int myArray[10];  // while declaring size must be mentiond.
    
    //initializing the above array using user input...

    cout<<"Enter elements of array \n";
    for (int i =0; i < 10; i++)
    {
        cin>>myArray[i]; // at each iteration elements are assigned in array
    }
    
    //dispaly elements of array using loop
    cout<<"You have entered the following elements \n";
    for (int i =0; i < 10; i++)
    {
        cout<<myArray[i]<<endl; // at each iteration elements are assigned in array
    }


    //find the maximum number in an array.
    int maxIndex = 0 ;
    for (int i =0; i < 10; i++)
    {
        if (maxIndex < i)
        {
            maxIndex = i;
        }
    }
    cout<<"The maximum number the array is \t"<<myArray[maxIndex]<<endl; // at each iteration elements are assigned in array



}