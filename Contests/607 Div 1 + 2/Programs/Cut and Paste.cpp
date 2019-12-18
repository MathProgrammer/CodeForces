#include <iostream>

using namespace std;

void solve()
{
    int no_of_steps;
    cin >> no_of_steps;
    
    string S;
    cin >> S;
    
    const int MAX = 1e6, MOD = 1e9 + 7;
    long long length = S.size();
    
    for(int i = 0; i < no_of_steps; i++)
    {
        long long suffix = ((length - 1) - i + MOD)%MOD;
        
        if(S[i] == '1')
        {
            continue;
        }
        else if(S[i] == '2')
        {
            length = (length + suffix)%MOD;
            
            for(int j = 1; j <= suffix && S.size() <= min(MAX, no_of_steps); j++)
            {
                S += S[i + j];
            }
        }
        else if(S[i] == '3')
        {
            length = (length + 2*suffix)%MOD;
            
            for(int k = 1; k <= 2; k++)
            {
                for(int j = 1; j <= suffix && S.size() <= min(MAX, no_of_steps); j++)
                {
                    S += S[i + j];
                }
            }
        }
    }
    
    cout << length << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
