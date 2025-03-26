//This code will prompt user to enter file name. (file should be in same path). Then 
// It will display the contents of file
#include <iostream>
#include <fstream>
#include <cstring>  // For C-strings
using namespace std;

int main() {
    char fileName[100];  // Array to store file name

    cout << "Enter the input file name: ";//if file is with extention enter with ext.
    cin >> fileName;  // Read file name

    ifstream inputFile;
    inputFile.open(fileName);  // Open the file

    if (!inputFile) {  // Check if the file was opened successfully
        cerr << "Error: Unable to open file " << fileName << endl;
        return 1;  // Exit with error
    }

    cout << "Contents of " << fileName << ":\n";

    char line[256];  // Buffer to store lines from the file
    while (inputFile.getline(line, sizeof(line))) {
        cout << line << endl;
    }

    inputFile.close();  // Close the file
    return 0;
}
