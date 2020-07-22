#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_piles;
    cin >> no_of_piles;

    vector <int> A(no_of_piles + 1);
    for(int i = 1; i <= no_of_piles; i++)
    {
        cin >> A[i];
    }
    
    int prefix_1s = 0;
    for(int i = 1; i <= no_of_piles && A[i] == 1; i++)
    {
        prefix_1s++;
    }
    
    if(prefix_1s == no_of_piles)
    {
        cout << (prefix_1s%2 == 0 ? "Second\n" : "First\n");
        
        return;
    }
    
    cout << (prefix_1s%2 == 0 ? "First\n" : "Second\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
