#include "min.h"
#include "max.h"
#include "mean.h"
#include "std.h"
#include <list>
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

    std::list<IStatistics *>list_statistics;

    list_statistics.push_back(new Min{});
    list_statistics.push_back(new Max{});
    list_statistics.push_back(new Mean{});
    list_statistics.push_back(new Std{});

    double val = 0;
    while (std::cin >> val) {
        for (const auto &_el : list_statistics)
            _el -> update(val);
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    for (const auto &_el : list_statistics)
        Statistics(_el, statistics_count);


    // Clear memory - delete all objects created by new
    for (const auto &_el : list_statistics)
        delete  _el;

    list_statistics.clear();

    return 0;
}
