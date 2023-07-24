#include "getmaxvalue.h"
#include "readwrite.h"

#include <string>
#include <iostream>
using namespace std;


void get_max_value(int argc, char** argv, int &max_value)
{
    string arg1_value{ argv[1] };
    if (arg1_value == "-max") {
        cout << "max argument was detected!" << endl;

        // We've detected the '-parameter' argument. And we extect that after this argument there is a value:
        if (argc < 3) {
            cout << "Wrong usage! The argument '-max' requires some value!" << endl;
        }
        // We need to parse the string to the int value
        max_value = stoi(argv[2]);
        cout << "The '-max' value = " << max_value << endl;
    }
    if (arg1_value == "-table") {
        read_the_high_score("high_scores.txt");
    }


}
