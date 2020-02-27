#include <iostream>

using namespace std;

void solve()
{
    int n, no_of_swaps, a, b;
    cin >> n >> no_of_swaps >> a >> b;

    int distance = (max(a, b) - min(a, b));
    cout << min(n - 1, no_of_swaps + distance) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
