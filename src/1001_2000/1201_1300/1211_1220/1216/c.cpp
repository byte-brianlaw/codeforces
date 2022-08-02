#include <algorithm>
#include <array>
#include <ios>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::ios_base;
using std::max;
using std::min;
using Paper = array<array<long long, 2>, 2>;

auto solve() {

    auto black_1 = Paper();
    auto black_2 = Paper();
    auto white = Paper();
    const auto inputPaper = [&](Paper& paper) {
        cin >> paper[0][0] >> paper[0][1] >> paper[1][0] >> paper[1][1];
    };

    inputPaper(white);
    inputPaper(black_1);
    inputPaper(black_2);

    const auto calculateCover = [&](Paper& paper) {
        return (
            max(min(paper[1][0], white[1][0]) - max(paper[0][0], white[0][0]), 0ll) *
            max(min(paper[1][1], white[1][1]) - max(paper[0][1], white[0][1]), 0ll)
        );
    };

    if (
        (
            calculateCover(black_1) + calculateCover(black_2) -
            (
                max(
                    (
                        min({black_1[1][0], black_2[1][0], white[1][0]}) -
                        max({black_1[0][0], black_2[0][0], white[0][0]})
                    ), 0ll
                ) * max(
                    (
                        min({black_1[1][1], black_2[1][1], white[1][1]}) -
                        max({black_1[0][1], black_2[0][1], white[0][1]})
                    ), 0ll
                )
            )
        ) == (white[1][0] - white[0][0]) * (white[1][1] - white[0][1])
    ) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    cout << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
