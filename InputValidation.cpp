#include "InputValidation.h"
#include <iostream>
#include <limits>

using namespace std;

bool readPositiveInt(const string &prompt, int &value)
{
    cout << prompt;
    if (!(cin >> value) || value <= 0)
    {
        cout << "Value must be a positive integer.\n";
        return false;
    }
    return true;
}

bool readNonNegativeInt(const string &prompt, int &value)
{
    cout << prompt;
    if (!(cin >> value) || value < 0)
    {
        cout << "Value must be a non-negative integer.\n";
        return false;
    }
    return true;
}

bool readDoubleValue(const string &prompt, double &value)
{
    cout << prompt;
    if (!(cin >> value))
    {
        cout << "Invalid numeric value.\n";
        return false;
    }
    return true;
}

bool readBatteryValue(const string &prompt, double &value)
{
    cout << prompt;
    if (!(cin >> value) || value < 0 || value > 100)
    {
        cout << "Battery must be between 0 and 100.\n";
        return false;
    }
    return true;
}

bool readNonEmptyLine(const string &prompt, string &value)
{
    cout << prompt;
    cin >> ws;
    getline(cin, value);
    if (value.empty())
    {
        cout << "Input cannot be empty.\n";
        return false;
    }
    return true;
}
