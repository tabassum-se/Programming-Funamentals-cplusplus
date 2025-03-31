// Demonstrate class in C++ version-2
// Constructore and Destructors
//

#include <iostream>
using namespace std;

class ClockType
{

private:
    int hr, min, sec;
public:
    ClockType();
    ClockType(int, int, int);

    void setTime(int,int,int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType&) const;

};

ClockType::ClockType()
{
    hr = min = sec = 0;
}

ClockType::ClockType(int h, int m, int s)
{
    //for hours

    if (0 <= h && h < 24)
    {
        hr = h;
    }
    else
    {
        hr = 0;
    }
    //for minutes
    if (0 <= m && m < 60)
    {
        min = m;
    }
    else
    {
        min = 0;
    }
    //for seconds

    if (0 <= s && s < 60)
    {
        sec = s;
    }
    else
    {
        sec = 0;
    }
}



void ClockType::setTime(int h, int m, int s)
{
    //for hours

    if (0 <= h && h < 24)
    {
        hr = h;
    }
    else
    {
        hr = 0;
    }
    //for minutes
    if (0 <= m && m < 60)
    {
        min = m;
    }
    else
    {
        min = 0;
    }
    //for seconds

    if (0 <= s && s < 60)
    {
        sec = s;
    }
    else
    {
        sec = 0;
    }
}

void ClockType::getTime(int& h, int& m, int& s) const
{
    h = hr;
    m = min;
    s = sec;
}

void ClockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";
    
    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec << ":";

}

void ClockType::incrementHours()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

void ClockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void ClockType::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

bool ClockType::equalTime(const ClockType& otherClock) const
{
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}


int main()
{
    ClockType myClock;
    ClockType yourClock;
    ClockType theirClock(24,23,45);

    theirClock.printTime();
    cout << endl;

    myClock.printTime();
    cout << endl;

    myClock.setTime(23,4,59);
    myClock.incrementSeconds();
    myClock.printTime();
    cout << endl;

    myClock.incrementHours();
    myClock.printTime();
    cout << endl;

    yourClock.setTime(5,59,16);
    yourClock.incrementMinutes();
    yourClock.printTime();
    cout << endl;


    if (myClock.equalTime(yourClock))
    {
        cout << "Both times are equal \n";
    }
    else
    {
        cout << "Both times are NOT equal \n";
    }

    return 0;
}

