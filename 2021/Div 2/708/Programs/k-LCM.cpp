#include <iostream>

using namespace std;

void solve_3(int n)
{
    switch(n%4)
    {
        case 1 :
        case 3 : cout << "1 " << n/2 << " " << n/2 << "\n"; return;

        case 2 : cout << "2 " << (n - 2)/2 << " " << (n - 2)/2 << "\n"; return;
        case 0 : cout << n/2 << " " << n/4 << " " << n/4 << "\n"; return;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k - 3; i++)
    {
        cout << "1 ";
    }

    solve_3(n - (k - 3));
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
