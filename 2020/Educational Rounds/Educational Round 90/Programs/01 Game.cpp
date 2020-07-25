#include <iostream>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    int zeroes = 0, ones = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '0')
        {
            zeroes++;
        }
        else
        {
            ones++;
        }
    }
    
    int no_of_moves = min(zeroes, ones);
    
    cout << (no_of_moves%2 == 1 ? "DA\n" : "NET\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
