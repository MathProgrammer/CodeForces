#include <iostream>

using namespace std;

void solve()
{
    int length, substring, distinct;
    cin >> length >> substring >> distinct;
    
    string S;
    for(int i = 0; i < length; i++)
    {
        if(i < substring)
        {
            if(i < distinct)
            {
                S += (char)('a' + i);
            }
            else
            {
                S += S.back();
            }
        }
        else
        {
            S += S[i - substring];
        }
    }
    
    cout << S << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
