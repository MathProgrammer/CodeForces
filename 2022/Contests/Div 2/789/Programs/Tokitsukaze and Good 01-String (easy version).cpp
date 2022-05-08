#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

char flip(char ch)
{
    return (ch == '0' ? '1' : '0');
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    string S;
    cin >> S;

    int minimum_changes = 0;
    int current_segment = 1;
    for(int i = 1; i < S.size(); i++)
    {
        if(S[i] != S[i - 1])
        {
            if(current_segment%2 == 1)
            {
                S[i] = flip(S[i]);
                minimum_changes++;
                current_segment = 2;
            }
            else
            {
                current_segment = 1;
            }
        }
        else
        {
            current_segment++;
        }
    }

    cout << minimum_changes << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

