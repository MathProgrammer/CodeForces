#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    
    long long d = (b - a);
    
    int moves = 0;
    
    if(d < 0)
    {
        moves = (d%2 == 0 ? 1 : 2);
    }
    else if(d > 0)
    {
        moves = (d%2 == 1 ? 1 : 2);
    }
    
    cout << moves << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
