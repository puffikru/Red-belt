#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:
    Table(size_t a, size_t b) {
        Resize(a, b);
    }

    pair<size_t, size_t> Size() const {
        return {table.size(), (table.empty() ? 0 : table[0].size())};
    }

    void Resize(size_t a, size_t b) {
        table.resize(a);
        for (auto& item : table) {
            item.resize(b);
        }
    }

    vector<T>& operator[](size_t index) {
        return table[index];
    }

    const vector<T>& operator[](size_t index) const {
        return table[index];
    }

private:
    vector<vector<T>> table;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}