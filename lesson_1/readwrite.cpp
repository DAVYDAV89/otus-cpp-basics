#include "readwrite.h"

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

