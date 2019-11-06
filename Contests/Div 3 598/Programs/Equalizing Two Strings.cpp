#include <iostream>
#include <vector>

using namespace std;

int parity(string &P)
{
    int inversions = 0;
    for(int i = 0; i < P.size(); i++)
    {
        for(int j = i + 1; j < P.size(); j++)
        {
            if(P[i] > P[j])
            {
                inversions++;
            }
        }
    }

    return (inversions%2);
}

void solve()
{
    int length;
    string S, T;
    cin >> length >> S >> T;

    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency_S(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < S.size(); i++)
    {
        frequency_S[S[i] - 'a']++;
    }

    vector <int> frequency_T(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < T.size(); i++)
    {
        frequency_T[T[i] - 'a']++;
    }

    int same_characters = true;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(frequency_S[i] != frequency_T[i])
        {
            same_characters = false;
        }
    }

    int duplicates_present = false;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(frequency_S[i] > 1)
        {
            duplicates_present = true;
        }
    }

    if(same_characters)
    {
        if(duplicates_present)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << (parity(S) == parity(T) ? "Yes\n" : "No\n");
        }
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
    {
        solve();
    }

    return 0;
}
