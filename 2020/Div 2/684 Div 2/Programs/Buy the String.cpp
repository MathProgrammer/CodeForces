#include <iostream>

using namespace std;

void solve()
{
    int length, cost[2], change;
    string S;
    cin >> length >> cost[0] >> cost[1] >> change >> S;
    
    int answer = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(change + cost[0] < cost[1])
        {
            if(S[i] == '1')
            {
                answer += change;
            }
            
            answer += cost[0];
        }
        else if(change + cost[1] < cost[0])
        {
            if(S[i] == '0')
            {
                answer += change;
            }
            
            answer += cost[1];
        }
        else if(change >= max(cost[0] - cost[1], cost[1] - cost[0]))
        {
            answer += cost[S[i] - '0'];
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
