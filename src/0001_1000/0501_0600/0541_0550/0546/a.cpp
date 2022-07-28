#include <algorithm>
#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;
using std::max;

auto solve() {

    auto k = 0;
    auto n = 0;
    auto w = 0;

    cin >> k >> n >> w;

    cout << max(k * w * (w + 1) / 2 - n, 0) << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
