#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string A, B, C;
    cin >> A >> B >> C;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == C[i] || B[i] == C[i])
        {
            continue;
        }
        
        cout << "NO\n";
        
        return;
    }
    
    cout << "YES\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
