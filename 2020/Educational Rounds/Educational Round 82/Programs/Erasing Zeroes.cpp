#include <iostream>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    int left_one = -1, right_one = -1;
    for(int i = S.size() - 1; i >= 0; i--)
    {
        if(S[i] == '1')
        {
            left_one = i;
        }
    }
    
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '1')
        {
            right_one = i;
        }
    }
    
    int zeroes = 0;
    for(int i = left_one; i <= right_one; i++)
    {
        if(S[i] == '0')
        {
            zeroes++;
        }
    }
    
    cout << zeroes << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
