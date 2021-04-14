#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    vector <int> target(2, 0), frequency(2, 0);
    string S;
    cin >> target[0] >> target[1] >> S;

    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] != '?')
        {
            frequency[S[i] - '0']++;
        }
    }

    int palindrome = true;
    for(int front_i = 0, back_i = S.size() - 1; front_i < back_i; front_i++, back_i--)
    {
       if(S[front_i] != '?' && S[back_i] == '?')
        {
            S[back_i] = S[front_i];
            frequency[S[back_i] - '0']++;

        }
        else if(S[back_i] != '?' && S[front_i] == '?')
        {
            S[front_i] = S[back_i];
            frequency[S[front_i] - '0']++;
        }


        if(S[front_i] != S[back_i])
        {
            palindrome = false;
        }
    }

    for(int front_i = 0, back_i = S.size() - 1; front_i <= back_i; front_i++, back_i--)
    {
        if(front_i == back_i)
        {
            if(S[front_i] == '?')
            {
                if(frequency[0] != target[0])
                {
                    S[front_i] = '0';
                }
                else if(frequency[1] != target[1])
                {
                    S[front_i] = '1';
                }

                frequency[S[front_i] - '0']++;
            }

            continue;
        }

        if(S[front_i] == '?' && S[back_i] == '?')
        {
            if(target[0] - frequency[0] >= 2)
            {
                S[front_i] = S[back_i] = '0';
                frequency[0] += 2;
            }
            else
            {
                S[front_i] = S[back_i] = '1';
                frequency[1] += 2;
            }
        }
    }

    if(frequency[0] != target[0] || frequency[1] != target[1] || !palindrome)
    {
        cout << "-1\n";
        return;
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


