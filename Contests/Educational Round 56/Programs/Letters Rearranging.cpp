#include <iostream>
#include <string>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;

    sort(all(S));

    cout << (S[0] == S[S.size() - 1] ? "-1" : S) << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
