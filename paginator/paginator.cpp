#include "test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

// Реализуйте шаблон класса Paginator


template<typename It>
class IteratorRange {
public:
    IteratorRange(It begin, It end, size_t page_size)
        : first(begin), last(end), p_size(page_size) {}

    It& begin() {
        return first;
    }

    It& end() {
        return last;
    }

    size_t size() const {
        return p_size;
    }

private:
    It first;
    It last;
    size_t p_size;
};


template<typename C>
auto Paginate(C& c, size_t page_size) {
    return IteratorRange{c.begin(), c.end(), page_size};
/*    cout << "size: " << c.size() << endl;

    auto it = c.begin();
    size_t p_size = c.size() % page_size > 0 ? c.size() / page_size + 1 : c.size() / page_size;

    cout << "p_size: " << p_size << endl;


    for (size_t i = 0; i < p_size; ++i) {
        for (auto j = 0; j < page_size; ++j) {
            if (it != c.end()) {
                ++it;
            } else {
                break;
            }
        }
//        result.push_back(Paginator<C>(c.begin(), it, static_cast<size_t>(distance(c.begin(), it))));
        Paginator{c.begin(), it, static_cast<size_t>(distance(c.begin(), it))};
    }
//    return Paginator{c.begin(), it, static_cast<size_t>(distance(c.begin(), it))};
    return Paginator{c.begin(), it, static_cast<size_t>(distance(c.begin(), it))};*/
}


template<typename Iterator>
class Paginator {
public:
//    Paginator() {};

    Paginator(const Iterator& begin, const Iterator& end, const size_t& page_size) {
//        IteratorRange<Iterator> ir{begin, end, page_size};
//        data.resize(RangeSize(ir));
//        cout << "it: " << distance(begin, end) << endl;
//        cout << "page_size: " << page_size << endl;
//        data.push_back({begin, end, page_size});
          data.push_back({begin, end, page_size});
    }

    typename vector<IteratorRange<Iterator>>::iterator begin() {
        return data.begin();
    }

    typename vector<IteratorRange<Iterator>>::iterator end() {
        return data.end();
    }

    size_t size() const {
        return data.size();
    }

    size_t RangeSize(IteratorRange<Iterator> r) {
        return r.end() - r.begin();
    }

private:
    vector<IteratorRange<Iterator>> data;
};


void TestPageCounts() {
    vector<int> v(15);

    ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
    ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
    ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
    ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
    ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
}

void TestLooping() {
    vector<int> v(15);
    iota(begin(v), end(v), 1);

    Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
    ostringstream os;
    for (const auto& page : paginate_v) {
        for (int x : page) {
            os << x << ' ';
        }
        os << '\n';
    }

    ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
}

void TestModification() {
    vector<string> vs = {"one", "two", "three", "four", "five"};
    for (auto page : Paginate(vs, 2)) {
        for (auto& word : page) {
            word[0] = toupper(word[0]);
        }
    }

    const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
    ASSERT_EQUAL(vs, expected);
}

void TestPageSizes() {
    string letters(26, ' ');

    Paginator letters_pagination(letters.begin(), letters.end(), 11);
    vector<size_t> page_sizes;
    for (const auto& page : letters_pagination) {
        page_sizes.push_back(page.size());
    }

    const vector<size_t> expected = {11, 11, 4};
    ASSERT_EQUAL(page_sizes, expected);
}

void TestConstContainer() {
    const string letters = "abcdefghijklmnopqrstuvwxyz";

    vector<string> pages;
    for (const auto& page : Paginate(letters, 10)) {
        pages.push_back(string(page.begin(), page.end()));
    }

    const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
    ASSERT_EQUAL(pages, expected);
}

void TestPagePagination() {
    vector<int> v(22);
    iota(begin(v), end(v), 1);

    vector<vector<int>> lines;
    for (const auto& split_by_9 : Paginate(v, 9)) {
        for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
            lines.push_back({});
            for (int item : split_by_4) {
                lines.back().push_back(item);
            }
        }
    }

    const vector<vector<int>> expected = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9},
        {10, 11, 12, 13},
        {14, 15, 16, 17},
        {18},
        {19, 20, 21, 22}
    };
    ASSERT_EQUAL(lines, expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestPageCounts);
//  RUN_TEST(tr, TestLooping);
//  RUN_TEST(tr, TestModification);
//  RUN_TEST(tr, TestPageSizes);
//  RUN_TEST(tr, TestConstContainer);
//  RUN_TEST(tr, TestPagePagination);

    /*vector<int> v(15);

    cout << v.size() << endl;

    v.push_back(1);

    cout << v.size() << endl;*/
}
