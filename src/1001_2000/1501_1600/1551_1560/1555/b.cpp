#include <algorithm>
#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

using std::array;
using std::cin;
using std::cout;
using std::fixed;
using std::ios_base;
using std::max;
using std::min;
using std::numeric_limits;
using std::setprecision;

auto solve() {

    auto room = array<int, 2>();
    auto table_1 = array<array<int, 2>, 2>();
    auto table_2 = array<int, 2>();
    const auto inputArray = [&](array<int, 2>& array_) {
        cin >> array_[0] >> array_[1];
    };

    inputArray(room);
    inputArray(table_1[0]);
    inputArray(table_1[1]);
    inputArray(table_2);

    auto distance = numeric_limits<int>::max();
    const auto minimizeDistance = [&](int dimension) {
        if (table_1[1][dimension] - table_1[0][dimension] + table_2[dimension] <= room[dimension]) {
            distance = min(
                {
                    table_2[dimension] - table_1[0][dimension],
                    table_2[dimension] - room[dimension] + table_1[1][dimension], distance
                }
            );
        }
    };

    minimizeDistance(0);
    minimizeDistance(1);

    distance = max(distance, 0);

    if (distance != numeric_limits<int>::max()) {
        cout << static_cast<double>(distance);
    } else {
        cout << -1;
    }

    cout << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    cout << fixed << setprecision(9);

    auto t = 0;

    cin >> t;

    for (auto i = 1; i <= t; ++i) {
        solve();
    }

    return 0;

}
