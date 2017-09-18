// HW1_function_templates
// Damir Pulatov
// 09/14/17
// A small C++ program to show how function templates work

#include <iostream>

using namespace std;

template
<typename T> T findMax(T number1, T number2);

int main()
{
    // Initialize two pairs of numbers of different data tyoes
    int int_1(5), int_2(-2), maxint;
    double double_1(9.59685), double_2(56907.8657), maxdouble;
    char char_1('a'), char_2('A'), maxchar;

    // Call function template and store return values
    maxint = findMax(int_1, int_2);
    maxdouble = findMax(double_1, double_2);
    maxchar = findMax(char_1, char_2);

    // Print results
    cout << "Maximum of " << int_1 << " and " << int_2 << " is " << maxint << endl;
    cout << "Maximum of " << double_1 << " and " << double_2 << " is " << maxdouble << endl;
    cout << "Maximum of " << char_1 << " and " << char_2 << " is " << maxchar << endl;

    return 0;
}

// function template that finds max of two data types
template <typename T>
T findMax(T number1, T number2)
{
    T max = number1;
    if (number1 < number2)
    {
        max = number2;
    }
    return max;
}
