#include <bitset>
#include <ios>
#include <iostream>
#include <string>

using std::bitset;
using std::cin;
using std::cout;
using std::ios_base;
using std::string;

auto solve() {

    auto k = 0;
    auto n = 0;
    auto s = string();

    cin >> n >> k >> s;

    auto pairs = 0;
    auto seen = bitset<26>();

    for (auto x : s) {
        pairs += seen[x - 'a'];
        seen[x - 'a'].flip();
    }

    auto length = pairs / k * 2;

    length += n - length * k >= k;

    cout << length << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    auto t = 0;

    cin >> t;

    for (auto i = 1; i <= t; ++i) {
        solve();
    }

    return 0;

}
