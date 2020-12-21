#include <iostream>

using namespace std;

void solve()
{
    int length;
    string S;
    
    cin >> length >> S;
    
    int suffix = 0;
    for(int i = length - 1; i >= 0; i--)
    {
        if(S[i] != ')')
        {
            break;
        }
        
        suffix++;
    }
    
    //cout << "String Read : " << S << " Suffix = " << suffix << "\n";
    
    int prefix = length - suffix;
    cout << (prefix < suffix ? "Yes" : "No") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
