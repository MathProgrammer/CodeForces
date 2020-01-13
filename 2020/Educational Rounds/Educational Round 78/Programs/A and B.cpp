#include <iostream>

using namespace std;

int possible(int x, int d)
{
    long long sum = x*(x + 1)/2;
    
    return (sum >= d && sum%2 == d%2);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    
    int moves = 0;
    while(!possible(moves, abs(a - b)))
    {
        moves++;
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
