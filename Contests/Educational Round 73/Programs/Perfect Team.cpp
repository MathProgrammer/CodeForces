#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int mathematicians, coders, normal;
    cin >> mathematicians >> coders >> normal;

    int teams = 0;
    if(normal >= min(mathematicians, coders))
    {
        teams = min(mathematicians, coders);
    }
    else
    {
        teams = normal;
        mathematicians -= teams;
        coders -= teams;

        if(2*min(mathematicians, coders) <= max(mathematicians, coders))
        {
            teams += min(mathematicians, coders);
        }
        else
        {
            teams += (mathematicians + coders)/3;
        }
    }

    cout << teams << "\n";
}

int main()
{
    int no_of_tests;
    cin >> no_of_tests;

    while(no_of_tests--)
        solve();

    return 0;
}
