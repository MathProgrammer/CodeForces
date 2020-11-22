#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int moves = 0;
    
    if(n == 2)
    {
        moves++;
    }
    else if(n%2 == 0)
    {
        moves = 2;
    }
    else if(n > 1)
    {
        moves = (n == 3 ? 2 : 3);
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
