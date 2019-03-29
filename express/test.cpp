
//   Q — количество запросов
//   M — максимальное значение модуля координаты



#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

using namespace std;

class RouteManager {
public:


    void AddRoute(int start, int finish) {
        reachable_lists_[start].insert(finish);    // logN + logN
        reachable_lists_[finish].insert(start);    // logN + logN
    }



    int FindNearestFinish(int start, int finish) const {
        int result = abs(start - finish);


        if (reachable_lists_.count(start) < 1) {  // N
            return result;
        }


        const set<int>& reachable_stations = reachable_lists_.at(start);  // logN


        const auto finish_pos = reachable_stations.lower_bound(finish);   // logN


        if (finish_pos != end(reachable_stations)) {
            result = min(result, abs(finish - *finish_pos));              // N
        }



        if (finish_pos != begin(reachable_stations)) {
            result = min(result, abs(finish - *prev(finish_pos)));       // N
        }


        return result;
    }


    // Add = logN
    // Find = N


private:
    map<int, set<int>> reachable_lists_;
};


int main() {
    RouteManager routes;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {

        // Q

        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;

        if (query_type == "ADD") {

            routes.AddRoute(start, finish);  // Q * logQ

        } else if (query_type == "GO") {

            cout << routes.FindNearestFinish(start, finish) << "\n";   // Q * Q

        }
    }

    // Q * logQ + Q^2

    return 0;
}










