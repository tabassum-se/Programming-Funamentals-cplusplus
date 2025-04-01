// SalesPersonData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

const int NO_OF_SALES_PERSON = 6;
struct salesPersonRec
{
    string ID;
    double salesByQuarter[4];
    double totalSale;
};

void initialize(ifstream& inData, salesPersonRec list[], int listSize)
{
    int quarter;
    int index;
    for (index = 0; index < listSize; index++)
    {
        inData >> list[index].ID; // get salesperson id
        

        for (quarter = 0; quarter < 4; quarter++)
        {
            list[index].salesByQuarter[quarter] = 0.0;
        }
        list[index].totalSale = 0.0;
    }
}


void getData(ifstream& infile, salesPersonRec list[], int listSize)
{
    int index;
    string sID;
    int month;
    double amount;
    int quarter;

    infile >> sID;
  

    while (infile)
    {
        infile >> month >> amount;

        for (index = 0; index < listSize; index++)
        {
            if (sID == list[index].ID)
            {
                break;
            }
        }

            if (1 <= month && month <= 3)
            {
                quarter = 0;
            }
            else if (4 <= month && month <= 6)
            {
                quarter = 1;
            }
            else if (7 <= month && month <= 9)
            {
                quarter = 2;
            }
            else 
            {
                quarter = 3;
            }

            if (index < listSize )
            {
                list[index].salesByQuarter[quarter] += amount;
            

            }
            else
            {
                cout << "invalid salesperson id"<<endl;
            }
            infile >> sID;
    


        //endl while loop
    }
}

//sales by quarter
void salesByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[])
{
    int quarter;
    int index;

    for (quarter = 0; quarter < 4; quarter++)
    {
        totalByQuarter[quarter] = 0.0;
    }

    for (quarter = 0; quarter < 4; quarter++)
    {
        for (index = 0; index < listSize; index++)
        {
            totalByQuarter[quarter] += list[index].salesByQuarter[quarter];
        }
    }
}

//print report
void printReport(ofstream& outfile, salesPersonRec list[], int listSize, double salesByQuarter[])
{
    int index;
    int quarter;

    outfile << "--------------------Annual Sals Report------------------------" << endl;
    outfile << endl;
    outfile << "  ID      QT1        QT2       QT3          QT4         Total" << endl;
    outfile << "---------------------------------------------------------------" << endl;

    cout << "  ID      QT1        QT2       QT3          QT4         Total" << endl;
    cout << "---------------------------------------------------------------" << endl;


    for (index = 0; index < listSize; index++)
    {
        outfile << list[index].ID << "  ";
        cout<< list[index].ID << "  ";
        for (quarter = 0; quarter < 4; quarter++)
        {
           outfile << setw(10) << list[index].salesByQuarter[quarter];
            cout<< setw(10) << list[index].salesByQuarter[quarter];
        }
        outfile << setw(10) << list[index].totalSale<<endl; 
        cout<< setw(10) << list[index].totalSale << endl;
    }
    outfile << "---------------------------------------------------------------" << endl;
    outfile << "Total   ";
    cout << "---------------------------------------------------------------" << endl;
    cout<< "Total   ";
    for (quarter = 0; quarter < 4; quarter++)
    {
        outfile << setw(10) << salesByQuarter[quarter];
        cout<< setw(10) << salesByQuarter[quarter];

    }
    outfile << endl << endl;
    cout<< endl << endl;
}



void totalSaleByPerson(salesPersonRec list[], int listSize, double totalByQuarter[])
{
    int index;
    int quarter;

    for (index = 0; index < listSize; index++)
    {
        list[index].totalSale = 0.0;  // Reset totalSale before summing
        for (quarter = 0; quarter < 4; quarter++)
        {
            list[index].totalSale += list[index].salesByQuarter[quarter];
        }
    }

}


int main()
{
    ifstream infile;
    ofstream outfile;

    string inputFile1 = "man.txt";
    string inputFile2 = "man2.txt";
    string outputFile = "man3.txt";

    double totalSalesByQurater[4];
    salesPersonRec salesPersonList[NO_OF_SALES_PERSON];

    //PROMPT USER TO ENTER FILE NAME
    //cout << "Enter file name to get IDs \n";
    //cin >> inputFile;
    //cout << endl;

    infile.open(inputFile1.c_str());

    if (!infile)
    {  
        cout << "can not open file \n";
        return 1;
    }
    initialize(infile, salesPersonList, NO_OF_SALES_PERSON);

    infile.close();
    infile.clear();

    //PROMPT USER TO ENTER FILE NAME
    //cout << "Enter file name to get Sales data \n";
    //cin >> inputFile;
    //cout << endl;

    infile.open(inputFile2.c_str());

    if (!infile)
    {
        cout << "can not open file \n";
        return 1;
    }
    //PROMPT USER TO ENTER FILE NAME
    //cout << "Enter output file name \n";
    //cin >> outputFile;
    //cout << endl;

    outfile.open(outputFile.c_str());
    outfile << fixed << showpoint << setprecision(2);

    getData(infile, salesPersonList, NO_OF_SALES_PERSON);

    salesByQuarter(salesPersonList, NO_OF_SALES_PERSON, totalSalesByQurater);

    totalSaleByPerson(salesPersonList, NO_OF_SALES_PERSON, totalSalesByQurater);
    printReport(outfile, salesPersonList, NO_OF_SALES_PERSON, totalSalesByQurater);

    infile.close();
    infile.clear();

    cout << "This table is also written in file name man3.txt!\n";

}
