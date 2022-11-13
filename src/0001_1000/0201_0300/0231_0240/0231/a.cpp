#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;

auto solve() {

    auto n = 0;

    cin >> n;

    auto implement = 0;

    for (auto i = 0; i < n; ++i) {
        auto petya = false;
        auto tonya = false;
        auto vasya = false;
        cin >> petya >> vasya >> tonya;
        implement += petya + tonya + vasya >= 2;
    }

    cout << implement << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
