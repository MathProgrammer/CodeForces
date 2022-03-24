#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long get_odd_part(long long n)
{
    while(n%2 == 0)
    {
        n = n >> 1;
    }

    return n;
}

void solve()
{
    long long n;
    cin >> n;

    if(n%2 == 1)
    {
        cout << "2\n";
        return;
    }

    long long original_n = n;
    long long odd_part = 1, even_part = 1;
    while(n%2 != 1)
    {
        n = n >> 1;

        even_part *= 2;
    }
    odd_part = n;
    //cout << "E = " << even_part << " O = " << odd_part << "\n";

    if(odd_part == 1)
    {
        cout << "-1\n";
        return;
    }

    cout << min(2*even_part, odd_part) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}



