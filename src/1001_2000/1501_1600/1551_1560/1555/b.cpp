#include <algorithm>
#include <array>
#include <iomanip>
#include <ios>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::fixed;
using std::ios_base;
using std::max;
using std::min;
using std::setprecision;

auto solve() {

    auto room = array<int, 2>();
    auto table_1 = array<array<int, 2>, 2>();
    auto table_2 = array<int, 2>();

    cin >> room[0] >> room[1] >> table_1[0][0] >> table_1[0][1] >> table_1[1][0] >> table_1[1][1] >>
    table_2[0] >> table_2[1];

    auto distance = max(room[0], room[1]);

    if (
        table_1[1][0] - table_1[0][0] + table_2[0] > room[0] &&
        table_1[1][1] - table_1[0][1] + table_2[1] > room[1]
    ) {
        distance = -1;
    } else {
        if (table_1[1][0] - table_1[0][0] + table_2[0] <= room[0]) {
            distance = min(max(table_2[0] - table_1[0][0], 0), distance);
            distance = min(max(table_2[0] - room[0] + table_1[1][0], 0), distance);
        }
        if (table_1[1][1] - table_1[0][1] + table_2[1] <= room[1]) {
            distance = min(max(table_2[1] - table_1[0][1], 0), distance);
            distance = min(max(table_2[1] - room[1] + table_1[1][1], 0), distance);
        }
    }

    if (distance != -1) {
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
