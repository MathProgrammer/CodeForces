#include <iostream>

using namespace std;

void solve()
{
    int length;
    string S;
    
    cin >> length >> S;
    
    int odd_count = 0;
    for(int i = 0; i < length; i++)
    {
        odd_count += (S[i] - '0')%2;
    }
    
    if(odd_count < 2)
    {
        cout << "-1\n";
        
        return;
    }
    
    string answer;
    for(int i = 0; i < length && answer.size() < 2; i++)
    {
        if( (S[i] - '0')%2 == 1)
        {
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
