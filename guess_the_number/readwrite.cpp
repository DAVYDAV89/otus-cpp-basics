#include "readwrite.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void write_new_high_score(string user_name, int attempts_count, const std::string high_scores_filename)
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

void read_the_high_score(const string high_scores_filename)
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
