// find average test score and out the average
// test score and all the test score less than average
// test score
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // array declaration
    int test[5];

    // necessary variables
    int sum;
    double average;
    int ind;

	// formatting output
    cout << fixed << showpoint << setprecision(2);
    cout << "Enter five test scores: ";
    for (ind = 0; ind < 5; ind++)
    {
        cin >> test[ind];
        sum = sum + test[ind];
    }
    cout << endl;
    average = sum / 5.0;
    cout << "The average test score = " << average << endl;
    for (ind = 0; ind < 5; ind++)
        if (test[ind] < average)
            cout << test[ind]
                 << " is less than the average test score." << endl;
    return 0;
}
