#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == 'm' || S[i] == 'w')
        {
            cout << "0\n";

            return 0;
        }
    }

    const int MOD = 1e9 + 7;

    vector <int> no_of_strings_till(S.size() + 1, 0);
    no_of_strings_till[0] = 1;

    for(int i = 1; i < S.size(); i++)
    {
        if(S[i] == 'n' && S[i - 1] == 'n')
        {
            if(i == 1)
            {
                no_of_strings_till[i] = 2;
                continue;
            }

            no_of_strings_till[i] = (no_of_strings_till[i - 1] + no_of_strings_till[i - 2])%MOD;
        }
        else if(S[i] == 'u' && S[i - 1] == 'u')
        {
            if(i == 1)
            {
                no_of_strings_till[i] = 2;
                continue;
            }

            no_of_strings_till[i] = (no_of_strings_till[i - 1] + no_of_strings_till[i - 2])%MOD;
        }
        else
        {
            no_of_strings_till[i] = no_of_strings_till[i - 1];
        }
    }

    cout << no_of_strings_till[S.size() - 1];

    return 0;
}
