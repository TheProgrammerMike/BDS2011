#include <iostream>

using namespace std;

double CheckInputNumber(double number)
{
    while ( ! (cin >> number))
    {
        // Enter this loop if input fails because of invalid data.

        cout << "Invalid input. Check for Character ";
        cin.clear ();   // reset the "failure" flag

        // The input "cursor" is still positioned at the beginning of
        // the invalid input, so we need to skip past it.

        cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.  This is why
                                  // you have to follow the input with
                                  // <return> or <enter>.
    }
    cout << "OK, you entered " << number << "." << endl;
    return number;
}