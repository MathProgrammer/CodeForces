#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int odd_till(int n)
{
    return (n/2) + n%2;
}

void solve()
{
    int left, right, no_of_operations;
    cin >> left >> right >> no_of_operations;

    int odd_integers = odd_till(right) - odd_till(left - 1);

    cout << (no_of_operations >= odd_integers || (left == right && left != 1) ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

