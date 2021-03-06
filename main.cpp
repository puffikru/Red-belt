#include "profile.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    {
        LOG_DURATION("endl");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << endl;
        }
    }
    {
        LOG_DURATION("'\\n'");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << '\n';
        }
    }
    return 0;
}