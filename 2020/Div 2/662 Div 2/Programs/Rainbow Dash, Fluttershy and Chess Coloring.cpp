#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int no_of_moves = n/2 + 1;
    
    cout << no_of_moves << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
