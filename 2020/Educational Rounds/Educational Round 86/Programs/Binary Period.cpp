#include <iostream>
#include <string>

using namespace std;

int is_periodic(string S, int period)
{
    for(int i = 0; i < S.size(); i++)
    {   //cout << "Comparing " << S[i] << " and " << S[i%period] << "\n";
        if(S[i] != S[i%period])
        {
            return false;
        }
    }
    
    return true;
}

char other(char ch)
{
    return (ch == '0' ? '1' : '0');
}

void solve()
{
    string S;
    cin >> S;
    
    if(is_periodic(S, 1))
    {
        cout << S << "\n";
        
        return;
    }
    
    string answer;
    for(int i = 0; i < S.size(); i++)
    {
        if(answer.size() == 0 || S[i] != answer.back())
        {
            answer += S[i];
        }
        else
        {
            answer += other(S[i]);
            answer += S[i];
        }
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
