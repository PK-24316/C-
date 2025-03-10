#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

///Function Prototypes
void calculateWaterBill();
void averagePerformanceCalculator();

int main()
{
    ///Variable Declarations
    bool blnRun = true;
    char chInput = '\0';

    //do while loop
    do
    {
        ///Print Menu
        cout << "Main Menu:\n" <<
                "A. Water Bill Calculator." <<
                "\nB. Overall Performance Calculator." <<
                "\nX. Exit App.\n" <<
                "Your Option: ";
        cin >> chInput;

        ///Switch case
        switch (tolower(chInput))
        {
        case 'a':
            cout << "Water Bill Calculator!\n";
            calculateWaterBill();
            break;
        case 'b':
            cout << "Overall Performance Calculator!\n";
            averagePerformanceCalculator();
            break;
        case 'x':
            ///Code to terminate the application
            cout << "Application Terminated!\n";
            blnRun = false;
            break;
        default:
            cerr << "Invalid Input!\n";
            exit(0); 
            break;
        }

    } while (blnRun); ///The application will continue while blnRun is true.

    return 0;
}

void calculateWaterBill()
{
    ///Variable declarations
    int Total_Water_Usage = 0;
    double Total_Water_Bill = 0.0; 

    ///Get input
    cout << "Enter Your Total Water Bill in cubic meters: ";
    cin >> Total_Water_Usage;

    ///Validate input
    while (cin.fail() || Total_Water_Usage < 0)
    {
        cerr << "Invalid Input!";
        cin.get();
        cin.ignore(100, '\n');
        exit(0);
    }

    ///Calculate The total price.
    if (Total_Water_Usage > -1 && Total_Water_Usage < 11)
        Total_Water_Bill = 0;
    else if (Total_Water_Usage > 9 && Total_Water_Usage < 31)
        Total_Water_Bill = Total_Water_Usage * 20;
    else if (Total_Water_Usage > 30)
        Total_Water_Bill = Total_Water_Usage * 40;

    ///Display results.
    cout << setprecision(2) << fixed; 
    cout << "Total Water Bill R: " << Total_Water_Bill << endl;
    cout << endl << endl;
}

void averagePerformanceCalculator()
{
    ///variable declarations
    double technicalSkills, communication, teamwork;
    double techWeight, commWeight, teamWeight;

    cout << "Enter score for Technical skills (0 - 100): ";
    // Input validation for technical skills
    while (!(cin >> technicalSkills) || technicalSkills < 0 || technicalSkills > 100) {
        cout << "Invalid input. Enter a score between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter score for Communication (0 - 100): ";
    // Input validation for communication score
    while (!(cin >> communication) || communication < 0 || communication > 100) {
        cout << "Invalid input. Enter a score between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter score for Teamwork (0 - 100): ";
    // Input validation for teamwork score
    while (!(cin >> teamwork) || teamwork < 0 || teamwork > 100) {
        cout << "Invalid input. Enter a score between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter weighting for Technical skills (0 - 1): ";
    // Input validation for technical skills weight
    while (!(cin >> techWeight) || techWeight < 0 || techWeight > 1) {
        cout << "Invalid input. Enter a weight between 0 and 1: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter weighting for Communication (0 - 1): ";
    // Input validation for communication weight
    while (!(cin >> commWeight) || commWeight < 0 || commWeight > 1) {
        cout << "Invalid input. Enter a weight between 0 and 1: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter weighting for Teamwork (0 - 1): ";
    // Input validation for teamwork weight
    while (!(cin >> teamWeight) || teamWeight < 0 || teamWeight > 1) {
        cout << "Invalid input. Enter a weight between 0 and 1: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check if the sum of the weights is approximately 1
    if (abs((techWeight + commWeight + teamWeight) - 1.0) > 0.0001) {
        cout << "Error: The sum of the weights must be 1." << endl;
        return; // Exit if the sum of weights is not 1
    }

    // Calculate the weighted performance score
    double performanceScore = (technicalSkills * techWeight) +
                              (communication * commWeight) +
                              (teamwork * teamWeight);

    // Output the result using conditional operator
    cout << (performanceScore < 50 ? "Intervention required." : "No intervention required.") << endl;
}




































