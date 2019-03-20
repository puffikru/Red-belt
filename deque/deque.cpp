//#include "test_runner.h"
#include <vector>
#include <stdexcept>
#include <iostream>
//#include <deque>

using namespace std;

template<typename T>
class Deque {
public:
    Deque() {
        front.resize(0);
        back.resize(0);
    }

    bool Empty() const {
        return front.empty() && back.empty();
    }

    size_t Size() const {
        return front.size() + back.size();
//        return Back() - Front();
    }

    T& operator[](const size_t& index) {
        return At(index);
    }

    const T& operator[](const size_t& index) const {
        return At(index);
    }

    T& At(const size_t& index) {
        if (index < front.size() + back.size()) {
            if (front.empty()) {
                return back[index];
            } else if (back.empty()) {
                return front[front.size() - 1 - index];
            } else {
                if (index < front.size()) {
                    return front[front.size() - 1 - index];
                } else if (index - front.size() < back.size()) {
                    return back[index - front.size()];
                }
            }
        } else {
            throw out_of_range("No such element");
        }
    }

    const T& At(const size_t& index) const {
        if (index < front.size() + back.size()) {
            if (front.empty()) {
                return back[index];
            } else if (back.empty()) {
                front[front.size() - 1 - index];
            } else {
                if (index < front.size()) {
                    return front[front.size() - 1 - index];
                } else if (index - front.size() < back.size()) {
                    return back[index - front.size()];
                }
            }
        } else {
            throw out_of_range("No such element");
        }
    }

    T& Front() {
        return front.empty() ? *(back.begin()) : front.back();
    }

    const T& Front() const {
        return front.empty() ? *(back.begin()) : front.back();
    }

    T& Back() {
        return back.empty() ? *(front.begin()) : back.back();
    }

    const T& Back() const {
        return back.empty() ? *(front.begin()) : back.back();
    }

    void PushFront(const T& item) {
        front.push_back(item);
    }

    void PushBack(const T& item) {
        back.push_back(item);
    }

private:
    vector<T> front;
    vector<T> back;
};

/*void TestEmpty() {
    Deque<int> d;
    ASSERT_EQUAL(d.Empty(), true);
}

void TestPushBack() {
    Deque<int> d;
    d.PushBack(1);
    d.PushBack(5);
    d.PushBack(6);
    ASSERT_EQUAL(d[0], 1);
    ASSERT_EQUAL(d[1], 5);
    ASSERT_EQUAL(d[2], 6);

    Deque<int> db;
    db.PushBack(1);
    ASSERT_EQUAL(db.Front(), 1);
    ASSERT_EQUAL(db.Back(), 1);
    ASSERT_EQUAL(db.Front(), db.Back());
}

void TestPushFront() {
    Deque<int> d;
    d.PushFront(1);
    d.PushFront(5);
    d.PushFront(6);
    ASSERT_EQUAL(d[0], 6);
    ASSERT_EQUAL(d[1], 5);
    ASSERT_EQUAL(d[2], 1);

    Deque<int> db;
    db.PushFront(1);
    ASSERT_EQUAL(db.Front(), 1);
    ASSERT_EQUAL(db.Back(), 1);
    ASSERT_EQUAL(db.Front(), db.Back());
}

void TestSize() {
    Deque<int> d;
    d.PushFront(1);
    d.PushFront(5);
    ASSERT_EQUAL(d.Size(), 2);
    d.PushBack(2);
    d.PushFront(7);
    ASSERT_EQUAL(d.Size(), 4);
}

void TestFront() {
    Deque<int> d;
    d.PushFront(1);
    ASSERT_EQUAL(d.Front(), 1);
    d.PushFront(5);
    ASSERT_EQUAL(d.Front(), 5);
    d.PushBack(2);
    d.PushFront(7);
    ASSERT_EQUAL(d.Front(), 7);

//    Deque<int> dq;
//    ASSERT_EQUAL(db.Front(), 1);
//    ASSERT_EQUAL(db.Back(), 1);
//    ASSERT_EQUAL(db.Front(), db.Back());
}

void TestBack() {
    Deque<int> d;
    d.PushBack(1);
    ASSERT_EQUAL(d.Back(), 1);
    d.PushFront(5);
    d.PushBack(2);
    d.PushFront(7);
    ASSERT_EQUAL(d.Back(), 2);
}



void TestAt() {
    Deque<int> d;
    d.PushBack(1);
    d.PushBack(1);
    d.PushBack(4);
    d.PushFront(2);
    d.PushBack(2);
    d.PushFront(4);
    d.PushFront(7);
    d.PushFront(4);
    ASSERT_EQUAL(d.At(0), 4);
    ASSERT_EQUAL(d.At(3), 2);
    ASSERT_EQUAL(d.At(5), 1);
    ASSERT_EQUAL(d.At(7), 2);
    ASSERT_EQUAL(d.At(7), d[7]);

    Deque<double> db;
    db.PushBack(1.0);
    db.PushBack(2.4);
    db.PushBack(3.9);
    db.PushFront(0.5);
    db.PushBack(2.2);
    db.PushFront(4.7);
    ASSERT_EQUAL(db.At(0), 4.7);
    ASSERT_EQUAL(db.At(3), 2.4);
    ASSERT_EQUAL(db.At(5), 2.2);

    Deque<char> cr;
    cr.PushBack('r');
    cr.PushBack('z');
    cr.PushBack('i');
    cr.PushFront('w');
    cr.PushBack('p');
    cr.PushFront('q');
    ASSERT_EQUAL(cr.At(0), 'q');
    ASSERT_EQUAL(cr.At(3), 'z');
    ASSERT_EQUAL(cr.At(5), 'p');

    try {
        d.At(8);
    } catch (const out_of_range& our) {
        ASSERT(our.what());
    }

    try {
        db[8];
    } catch (const out_of_range& our) {
        ASSERT(our.what());
    }

}*/



int main() {
    /*TestRunner tr;
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestPushBack);
    RUN_TEST(tr, TestPushFront);
    RUN_TEST(tr, TestSize);
    RUN_TEST(tr, TestFront);
    RUN_TEST(tr, TestBack);
    RUN_TEST(tr, TestAt);*/

    /*Deque<int> d;
    d.PushBack(1);
    d.PushFront(5);
    d.PushBack(2);
    d.PushFront(7);

    for (auto i = 0; i < d.Size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << d[0] << endl;
    cout << d.At(0) << endl;
    cout << d.Front() << endl;
    cout << d.Back() << endl;
    cout << d.Size() << endl;*/
//    cout << d[4] << endl;
//    cout << d.At(4) << endl;



    /*deque<int> dq;

    dq.push_back(1);
    dq.push_back(1);
    dq.push_back(1);
    dq.push_back(1);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;*/

    return 0;
}