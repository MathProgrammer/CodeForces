#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int budget;
    cin >> budget;
    
    long long no_of_moves = 0;
    while(budget >= 10)
    {
        long long move = budget/10;
        
        budget = budget - 10*move + move;
        
        no_of_moves += 10*move;
    }
    
    no_of_moves += budget;
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
