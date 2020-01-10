#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    vector <int> answer;
    for(int i = 4; i < S.size(); i++)
    {
        if(S[i] == 'e' and S[i - 1] == 'n' and S[i - 2] == 'o' 
            and S[i - 3] == 'w' and S[i - 4] == 't')
        {
            S[i - 2] = 'x';
            
            answer.push_back(i - 2 + 1);
        }
        
    }
    
    for(int i = 2; i < S.size(); i++)
    {
        if(S[i] == 'o' and S[i - 1] == 'w' && S[i - 2] == 't')
        {
            answer.push_back(i - 1 + 1);
        }
        
        if(S[i] == 'e' and S[i - 1] == 'n' && S[i - 2] == 'o')
        {
            answer.push_back(i - 1 + 1);
        }
    }
    
    cout << answer.size() << "\n";
    
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
