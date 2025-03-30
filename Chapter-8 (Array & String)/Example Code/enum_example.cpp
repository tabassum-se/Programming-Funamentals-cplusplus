//ENUM in C++

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    enum paintTpye {GREEN, RED, BLUE, BROWN, WHITE, ORANGE, YELLOW};

    double paintSale[7];

    paintTpye paint;

    for (paint = GREEN; paint <= YELLOW; paint = static_cast<paintTpye>(paint + 1))
    {
        paintSale[paint] = (1 + rand() % 100); // random 0 -100
    }
    //for between 10 and 50 rand() % (50 - 10 + 1)
   
    for (paint = GREEN; paint <= YELLOW; paint = static_cast<paintTpye>(paint + 1))
    {
        cout<<paintSale[paint]<<endl;
    }
   
    return 0;
}

