#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    int answer = 0, last_r = -1;
    for(int i = 0; i <= S.size(); i++)
    {
        if(i == S.size() || S[i] == 'R')
        {
            answer = max(answer, i - last_r);
            
            last_r = i;
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
