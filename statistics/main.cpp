#include "min.h"
#include "max.h"
#include "mean.h"
#include "std.h"
#include <iostream>

template < typename T >
void Statistics ( T & _el, const size_t _statistics_count )
{
    // Print results if any
    for (size_t i = 0; i < _statistics_count; ++i) {
        std::cout << _el[i].name() << " = " << _el[i].eval() << std::endl;
    }
}

int main() {

    const size_t statistics_count = 1;

    IStatistics *statistics_min[statistics_count];
    IStatistics *statistics_max[statistics_count];
    IStatistics *statistics_mean[statistics_count];
    IStatistics *statistics_std[statistics_count];

    statistics_min[0] = new Min{};
    statistics_max[0] = new Max{};
    statistics_mean[0] = new Mean{};
    statistics_std[0] = new Std{};

    double val = 0;
    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics_min[i] -> update(val);
            statistics_max[i] -> update(val);
            statistics_mean[i] -> update(val);
            statistics_std[i] -> update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    Statistics(statistics_min[0], statistics_count);
    Statistics(statistics_max[0], statistics_count);
    Statistics(statistics_mean[0], statistics_count);
    Statistics(statistics_std[0], statistics_count);

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics_min[i];
        delete statistics_max[i];
        delete statistics_mean[i];
        delete statistics_std[i];
    }

    return 0;
}
