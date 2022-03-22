#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    int minimum_moves = 0, remaining = length;
    for(int i = 0; i  + 1 < length; i++)
    {
        if(S[i] == '(')
        {
            minimum_moves++;
            remaining -= 2;
            i++;
        }
        else if(S[i] == ')')
        {
            int j = i + 1;
            while(j < length && S[j] != ')')
            {
                j++;
            }

            if(j == length)
            {
                break;
            }

            minimum_moves++;
            remaining -= (j - i + 1); //cout << "i = " << i << " j = " << j << "\n";
            i = j;
        }
    }

    cout << minimum_moves << " " << remaining << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

