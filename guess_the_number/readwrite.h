#pragma once

#include <string>

void write_new_high_score(std::string user_name, int attempts_count, const std::string high_scores_filename);
void read_the_high_score(const std::string high_scores_filename);

