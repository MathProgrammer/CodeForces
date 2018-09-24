#include <iostream>

using namespace std;

int is_proper(string S)
{
    int upper_case = 0, lower_case = 0, digits = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if('a' <= S[i] && S[i] <= 'z') lower_case++;
        if('A' <= S[i] && S[i] <= 'Z') upper_case++;
        if('0' <= S[i] && S[i] <= '9') digits++;
    }

    return (upper_case > 0 && lower_case > 0 && digits > 0);
}

void solve()
{
    string S;
    cin >> S;

    int upper_case = 0, lower_case = 0, digits = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if('a' <= S[i] && S[i] <= 'z') lower_case++;
        if('A' <= S[i] && S[i] <= 'Z') upper_case++;
        if('0' <= S[i] && S[i] <= '9') digits++;
    }

    if(upper_case > 0 && lower_case > 0 && digits > 0)
    {
        cout << S << "\n";
        return;
    }
    else if(upper_case == 0 && lower_case == 0 && digits > 0)
    {
        S[0] = 'A'; S[1] = 'a';

        cout << S << "\n";
        return;
    }
    else if(upper_case == 0 && lower_case > 0 && digits == 0)
    {
        S[0] = 'A'; S[1] = '0';

        cout << S << "\n";
        return;
    }
    else if(upper_case > 0 && lower_case == 0 && digits == 0)
    {
        S[0] = 'a'; S[1] = '0';

        cout << S << "\n";
        return;
    }

    for(int i = 0; i < S.size(); i++)//Runs at most 2 times.
    {
        char original = S[i];

        S[i] = '0'; if(is_proper(S)){cout << S << "\n"; return;}
        S[i] = 'a'; if(is_proper(S)){cout << S << "\n"; return;}
        S[i] = 'A'; if(is_proper(S)){cout << S << "\n"; return;}

        S[i] = original;
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

