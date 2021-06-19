#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int rows, columns, i, j;
    cin >> rows >> columns >> i >> j;

    int x1 = (2*i <= rows ? rows : 1);
    int y1 = (2*j <= columns ? columns : 1);

    int x2 = (x1 == 1 ? rows : 1);
    int y2 = (y1 == 1 ? columns : 1);

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

