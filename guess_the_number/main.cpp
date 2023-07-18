#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const string high_scores_filename = "high_scores.txt";
string user_name;
int attempts_count = 0;

void write_new_high_score()
{
    // We should open the output file in the append mode - we don't want
    // to erase previous results.
    ofstream out_file{high_scores_filename, ios_base::app};
    if (!out_file.is_open()) {
        cout << "Failed to open file for write: " << high_scores_filename << "!" << endl;
        return;
    }

    // Append new results to the table:
    out_file << user_name << ' ';
    out_file << attempts_count;
    out_file << endl;
} // end of score here just to mark end of the logic block of code


void read_the_high_score()
{
    ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        cout << "Failed to open file for read: " << high_scores_filename << "!" << endl;
        return;
    }

    string username;
    int high_score = 0;
    vector<pair<string, int>> records;
    while (true) {
        // Read the username first
        in_file >> username;
        // Read the high score next
        in_file >> high_score;
        // Ignore the end of line symbol
        in_file.ignore();

        records.push_back(make_pair(username, high_score));

        if (in_file.fail()) {
            break;
        }
    }

    // Создаем словарь для хранения рекордов
    unordered_map<string, vector<int>> highScores;

    // Обрабатываем каждую запись в таблице рекордов
    for (const auto& record : records) {
        const string& user = record.first;
        int score = record.second;

        // Если пользователь уже есть в словаре, добавляем новый результат
        if (highScores.count(user)) {
            highScores[user].push_back(score);
        }
        // Если пользователь еще не встречался, создаем новую запись
        else {
            highScores[user] = {score};
        }
    }

    // Выводим только минимальные значения попыток для каждого пользователя
    cout << "High scores table:" << endl;
    for (const auto& entry : highScores) {
        const string& user = entry.first;
        const vector<int>& scores = entry.second;

        int minScore = *min_element(scores.begin(), scores.end());
        cout << user << " " << minScore << endl;
    }
    // Print the information to the screen
}

int main(int argc, char** argv)
{
    int max_value = 0;
    // Let's print this argument
    if (argc > 0) {
        max_value = 100;
    }

    // To check - does use print some other argument we should check if the argc >= 2
    if (argc >= 2) {
        string arg1_value{ argv[1] };
        if (arg1_value == "-max") {
            cout << "max argument was detected!" << endl;

            // We've detected the '-parameter' argument. And we extect that after this argument there is a value:
            int parameter_value = 0;
            if (argc < 3) {
                cout << "Wrong usage! The argument '-max' requires some value!" << endl;
                return -1;
            }
            // We need to parse the string to the int value
            max_value = stoi(argv[2]);
            cout << "The '-max' value = " << max_value << endl;
        }
        if (arg1_value == "-table") {
            read_the_high_score();
            return 0;
        }
    }


    // Ask about name
    cout << "Hi! Enter your name, please:" << endl;
    cin >> user_name;

    srand(time(nullptr));

    const int target_value = rand() % max_value;
//    cout << "guess: " << target_value;

    int current_value = 0;

    cout << "Enter your guess:" << endl;

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

    write_new_high_score();
    read_the_high_score();


    return 0;
}
