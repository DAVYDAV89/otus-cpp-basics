#include <ctime>
#include <iostream>
#include "readwrite.h"
#include "getmaxvalue.h"

using namespace std;

int main(int argc, char** argv)
{
    const std::string high_scores_filename = "high_scores.txt";

    int max_value = 0;
    // Let's print this argument
    if (argc > 0) {
        max_value = 100;
    }
    // To check - does use print some other argument we should check if the argc >= 2
    if (argc >= 2) {
        get_max_value(argc, argv, max_value);
    }

    // Ask about name
    cout << "Hi! Enter your name, please:" << endl;
    std::string user_name;
    cin >> user_name;

    srand(time(nullptr));

    const int target_value = rand() % max_value;
//    cout << "guess: " << target_value;

    int current_value = 0;

    cout << "Enter your guess:" << endl;

    int attempts_count = 0;
    do {
        cin >> current_value;
        attempts_count++;

        if (current_value < target_value) {
            cout << "less than " << current_value << endl;
        }
        else if (current_value > target_value) {
            cout << "greater than " << current_value << endl;
        }
        else {
            cout << "you win! attempts = " << attempts_count << endl;
            break;
        }

    } while(true);

    write_new_high_score(user_name, attempts_count, high_scores_filename);
    read_the_high_score(high_scores_filename);

    return 0;
}
