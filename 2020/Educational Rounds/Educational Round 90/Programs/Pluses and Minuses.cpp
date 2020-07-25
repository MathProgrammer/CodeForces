#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    long long res = 0;
    for(long long i = 0, balance = 0, initial_balance = 0; i < S.size(); i++)
    {
        if(S[i] == '+')
        {
            balance++;
        }
        else
        {
            balance--;
        }
        
        if(initial_balance + balance < 0)
        {
            int no_of_retries = abs(initial_balance + balance);
            
            initial_balance += no_of_retries;
            
            res += no_of_retries*(i + 1); 
        }
    }
    
    res += S.size();
    
    cout << res << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
