#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <typename Iterator>
struct IteratorRange {
    Iterator first, last;

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }
};


template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) {
    return {
        v.begin(), next(v.begin(), min(top, v.size()))
    };
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    for (int& x : Head(v, 3)) {
        ++x;
    }
    for (int x : v) {
        cout << x << ' ';
    }
    return 0;
}


/*struct PairOfStringAndInt {
    string first;
    int second;
};

struct PairOfBoolAndChar {
    bool first;
    char second;
};


template <typename T, typename U>
struct Pair {
    T first;
    U second;
};


int main() {
    Pair<string, int> si;
    si.first = "Hello";
    si.second = 5;

    Pair<bool, char> bc;
    bc.first = true;
    bc.second = 'z';

    return 0;
}*/


