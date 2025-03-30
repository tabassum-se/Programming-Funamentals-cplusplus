// usin const to prevent modification in array
 //passing array to function
//
#include <iostream>
#include <iomanip>
using namespace std;

//prototype of functions
void addElement(const int arr1[], int size)
{
    int temp_array[5];
    //add one element in arrat
    for (int i = 0; i < 5; i++)
    {
        temp_array[i] = arr1[i] ;
        temp_array[i] = temp_array[i] + 1;
    }

    //display inside function
    cout<<"\n Display inside array \n";
    for (int i = 0; i < 5; i++)
    {
        cout<<temp_array[i]<<", ";
    }

}
int main()
{
    int arr1[5] = {1,2,3,4,5};
    cout<<"original array is : \n";
    for (int i = 0; i < 5; i++)
    {
        cout<<arr1[i]<<", ";
    }
    //passing array to function that adds 1 in each element of array.
    addElement(arr1, 5);

    // display inside main
    cout<<"original array inside main function : \n";
    for (int i = 0; i < 5; i++)
    {
        cout<<arr1[i]<<", ";
    }
    
    
    return 0;
}

