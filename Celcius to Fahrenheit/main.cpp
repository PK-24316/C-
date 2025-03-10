#include <iostream>
#include <iomanip>

using namespace std;

///Declare Const Variables.
const int Week1 = 28;
const int Week2 = 22; 
const int Week3 = 25;
const int Week4 = 30;
const int Week5 = 19;
const int Week6 = 27;
const int Week7 = 23;
const int Week8 = 31;
const int Week9 = 26;
const int Week10 = 20;

///Function Prototypes
double convert_fahrenheit(double celsius);

int main()
{

    ///Variable Declarations
    double average_temp = 0.0;
    int sum = 0;
    
    ///Calculate The sum of the temparatures
    sum = Week1 + Week2 + Week3 + Week4 + Week5 + Week6 + Week7 + Week8 + Week9 + Week10;

    ///Calculate the average temperature
    average_temp = static_cast<double>(sum)/10;

    ///Convert the average temperature in degree celsius to fahrenheit
    double fahrenheit = convert_fahrenheit(average_temp);
     
    ///Convert the weekly degree celsius temperatures to fahrenheit
    double Fahrenheit_Week1 = convert_fahrenheit(Week1);
    double Fahrenheit_Week2 = convert_fahrenheit(Week2);
    double Fahrenheit_Week3 = convert_fahrenheit(Week3);
    double Fahrenheit_Week4 = convert_fahrenheit(Week4);
    double Fahrenheit_Week5 = convert_fahrenheit(Week5);
    double Fahrenheit_Week6 = convert_fahrenheit(Week6);
    double Fahrenheit_Week7 = convert_fahrenheit(Week7);
    double Fahrenheit_Week8 = convert_fahrenheit(Week8);
    double Fahrenheit_Week9 = convert_fahrenheit(Week9);
    double Fahrenheit_Week10 = convert_fahrenheit(Week10);

    ///Round off to two decimal places.
    cout << setprecision(2) << fixed;

    ///Display results.
    cout << "\nWeekly Tempature in Degrees Celsius:\n";
    cout << "Week 1\tWeek 2\tWeek 3\tWeek 4\tWeek 5\tWeek 6\tWeek 7\tWeek 8\tWeek 9\tWeek 10\n" <<
            Week1 << "\t" << Week2 << "\t" << Week3 << "\t" << Week4 << "\t" << Week5 << "\t" << Week6 << "\t" << Week7 << "\t"
            << Week8 << "\t" << Week9 << "\t" << Week10 << "\n"; 

    cout << "\nWeekly Tempature in Degrees Fahrenheit:\n";
    cout << "Week 1\tWeek 2\tWeek 3\tWeek 4\tWeek 5\tWeek 6\tWeek 7\tWeek 8\tWeek 9\tWeek 10\n" <<
            Fahrenheit_Week1 << "\t" << Fahrenheit_Week2 << "\t" << Fahrenheit_Week3 << "\t" << Fahrenheit_Week4 << "\t" << Fahrenheit_Week5 << "\t" 
            << Fahrenheit_Week6 << "\t" << Fahrenheit_Week7 << "\t" << Fahrenheit_Week8 << "\t" << Fahrenheit_Week9 << "\t" << Fahrenheit_Week10 << "\n"; 
    
    cout << "\nAverage Weekly Temperature in Degrees Celsius: " << average_temp << endl <<
            "Average Weekly Temperature in Degrees Fahrenheit: " << fahrenheit << endl;

    return 0;
}

double convert_fahrenheit(double celsius)
{
    ///Declare and initialize variable
    double result = 0.0;
    
    ///Calculation to convert to fahrenheit
    result = (celsius * 9/5) + 32;

    ///return the answer
    return result;
}