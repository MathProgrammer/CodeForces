#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length, balance;
    cin >> length >> balance;
    
    string S;
    cin >> S;
    
    vector <int> frequency(2, 0);
    for(int i = 0; i < length; i++)
    {
        frequency[S[i] - '0']++;
    }
    
    int whole_balance = frequency[0] - frequency[1];
    
    int no_of_prefixes = (balance == 0 ? 1 : 0);
    
    frequency[0] = 0; frequency[1] = 0;
    
    for(int i = 0; i < length; i++)
    {
        frequency[S[i] - '0']++;
        
        int prefix_balance = frequency[0] - frequency[1];
        
        if(whole_balance != 0 && ((balance - prefix_balance)%whole_balance == 0 && (balance - prefix_balance)/whole_balance >= 0))
        {
            no_of_prefixes++;
        }
        
        if(whole_balance == 0 && prefix_balance == balance)
        {
            cout << "-1\n";
            
            return;
        }
    }
    
    cout << no_of_prefixes << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
