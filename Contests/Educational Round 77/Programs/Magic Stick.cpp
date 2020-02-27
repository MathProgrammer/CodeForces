#include <iostream>

using namespace std;

void solve()
{
    long long x, y;
    cin >> x >> y;

    if(x == 1 || x == 3)
    {
        cout << (x >= y ? "Yes\n" : "No\n");

        return;
    }
    else if(x == 2)
    {
        cout << (y <= 3 ? "Yes\n" : "No\n");

        return;
    }

    cout << "Yes\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

