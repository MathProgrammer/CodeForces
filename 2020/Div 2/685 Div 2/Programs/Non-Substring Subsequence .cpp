#include <iostream>

using namespace std;

void solve()
{
    int length, queries;
    cin >> length >> queries;
    
    string S;
    cin >> S;
    
    for(int i = 1; i <= queries; i++)
    {
        int left, right;
        cin >> left >> right;
        
        int answer_found = false;
        for(int i = right + 1; i <= length; i++)
        {
            if(S[right - 1] == S[i - 1])
            {
                cout << "YES\n";
                answer_found = true;
                break;
            }
        }
        
        if(answer_found)
        {
            continue;
        }
        
        for(int i = 1; i < left; i++)
        {
            if(S[i - 1] == S[left - 1])
            {
                cout << "YES\n";
                answer_found = true;
                break;
            }
        }
        
        if(answer_found)
        {
            continue;
        }
        
        cout << "NO\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
