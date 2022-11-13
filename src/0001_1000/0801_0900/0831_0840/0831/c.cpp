#include <ios>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::ios_base;
using std::unordered_map;
using std::unordered_set;
using std::vector;

auto solve() {

    auto k = 0;
    auto n = 0;

    cin >> k >> n;

    auto a = vector<int>(k);

    for (auto& x : a) {
        cin >> x;
    }

    auto first = 0;

    cin >> first;

    auto differences = unordered_map<int, int>();

    for (auto i = 0; i < n - 1; ++i) {
        auto points = 0;
        cin >> points;
        ++differences[points - first];
    }

    auto initial = unordered_set<int>();
    auto running = 0;

    for (auto i = 0; i < k; ++i) {
        auto accumulated = 0;
        auto current = unordered_map<int, int>();
        for (auto j = i; j; --j) {
            accumulated -= a[j];
            ++current[accumulated];
        }
        accumulated = 0;
        for (auto j = i + 1; j < k; ++j) {
            accumulated += a[j];
            ++current[accumulated];
        }
        running += a[i];
        auto valid = true;
        for (const auto& x : differences) {
            if (current[x.first] < x.second) {
                valid = false;
                break;
            }
        }
        if (valid) {
            initial.insert(running);
        }
    }

    cout << initial.size() << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
