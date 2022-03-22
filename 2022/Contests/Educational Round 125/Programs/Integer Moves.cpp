#include <iostream>

using namespace std;

int is_square(int n)
{
    for(int i = 1; i*i <= n; i++)
    {
        if(i*i == n)
        {
            return true;
        }
    }

    return false;
}

void solve()
{
    int x, y;
    cin >> x >> y;

    int answer = 0;
    if(x == 0 && y == 0)
    {
        answer = 0;
    }
    else if(is_square(x*x + y*y))
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
