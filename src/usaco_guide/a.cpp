#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::ios_base;
using std::max;
using std::vector;

auto solve() {

    auto n = 0;

    cin >> n;

    auto points = vector<array<int, 2>>(n);

    for (auto& x : points) {
        cin >> x[0];
    }

    for (auto& x : points) {
        cin >> x[1];
    }

    auto distance_squared = 0;

    for (auto i = 0; i < n; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            const auto x_distance = points[j][0] - points[i][0];
            const auto y_distance = points[j][1] - points[i][1];
            distance_squared = max(
                x_distance * x_distance + y_distance * y_distance, distance_squared
            );
        }
    }

    cout << distance_squared << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
