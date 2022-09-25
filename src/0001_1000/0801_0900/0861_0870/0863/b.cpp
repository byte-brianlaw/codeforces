#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::ios_base;
using std::min;
using std::sort;
using std::vector;

auto solve() {

    auto n = 0;

    cin >> n;

    auto w = vector<int>(n * 2);

    for (auto& x : w) {
        cin >> x;
    }

    sort(w.begin(), w.end());

    auto instability = 50000;

    for (auto i = 0; i < n * 2; ++i) {
        for (auto j = i + 1; j < n * 2; ++j) {
            auto current = 0;
            auto previous = 0;
            for (auto k = 0; k < n * 2; ++k) {
                if (k == i || k == j) {
                    continue;
                }
                if (previous) {
                    current += w[k] - previous;
                    previous = 0;
                } else {
                    previous = w[k];
                }
            }
            instability = min(current, instability);
        }
    }

    cout << instability << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
