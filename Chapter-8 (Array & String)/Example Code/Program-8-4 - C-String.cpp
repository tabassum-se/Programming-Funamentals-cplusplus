//Program to demonstrate some built-in functions of C-string
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	//declaration of characters arrays.
	char studentName[21];
	char myName[16];
	char yourName[16];
	
	//applying built-in functions.
	strcpy(myName, "nm");
	strlen("Khan Ahmad");
	cout<<"The length of myName is "<<strlen(myName)<<endl;
	int len;
	len = strlen("Sunny Day");
	
	//comparison and copy operations.
	strcpy(yourName, "Khan");
	cout<<"The length of yourName is "<<strlen(yourName)<<endl;

	strcpy(studentName, yourName);
	strcmp("aleem","naeem");
	
	cout<<strcmp(myName, yourName);
return 0;
}