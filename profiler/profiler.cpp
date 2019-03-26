#include "profile.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>

using namespace std;

int main() {
    LOG_DURATION("Total");

    ifstream in("input.txt");
    int element_count;
    in >> element_count;

    set<int> elements;

    {
        LOG_DURATION("Input");
        for (int i = 0; i < element_count; ++i) {
            int x;
            in >> x;
            elements.insert(x);
        }
    }

    int query_count;
    in >> query_count;

    int total_found = 0;
    {
        LOG_DURATION("Queries processing");
        for (int i = 0; i < query_count; ++i) {
            LOG_DURATION("Iter " + to_string(i));
            int x;
            in >> x;
            if (element.find(x) != elements.end()) {
                ++total_found;
            }
        }
    }

    return 0;
}