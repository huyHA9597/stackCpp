#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "stackType.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Step 1
    double GPA;
    double highestGPA;
    string name;
    stackType<string> stack(100);

    ifstream infile;

    // Step 2
    infile.open("HighestGPAData.txt");

    // Step 3
    if (!infile)
    {
        cout << "The input file does not exist."
             << "Program termintates.\n";
        return 1;
    }

    // Step 4
    cout << fixed << showpoint << setprecision(2);

    // Step 5
    infile >> GPA >> name;

    // Step 6
    highestGPA = GPA;

    // Step 7
    while (infile)
    {
        if (GPA > highestGPA)
        {
            stack.initializeStack();

            if (!stack.isFullStack())
                stack.push(name);

            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
            if (!stack.isFullStack())
                stack.push(name);
            else
            {
                cout << "Stack overflows. "
                     << "Program terminates!\n";

                return 1;       // exit program     
            }
        infile >> GPA >> name;       
    }   

    // Step 8
    cout << "Highest GPA = " << highestGPA
         << endl;
    cout << "The students holding the "
         << "highest GPA are: " << endl;

    // Step 9
    while (!stack.isEmptyStack())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << endl;
    return 0;
}
