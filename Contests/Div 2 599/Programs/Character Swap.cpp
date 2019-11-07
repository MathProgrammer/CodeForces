#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int length;
    cin >> length;

    string S, T;
    cin >> S >> T;

    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < length; i++)
    {
        frequency[S[i] - 'a']++;
        frequency[T[i] - 'a']++;
    }

    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(frequency[i]%2 == 1)
        {
            cout << "No\n";

            return;
        }
    }

    vector <pair <int, int> > swaps;
    for(int i = 0; i < length; i++)
    {
        if(S[i] == T[i])
        {
            continue;
        }

        for(int j = i + 1; j < length; j++)
        {
            if(S[j] == T[j])
            {
                continue;
            }

            if(S[i] == T[j])
            {
                swap(S[j], T[j]);

                swaps.push_back(make_pair(j, j));
            }

            if(S[i] == S[j])
            {
                swap(S[j], T[i]);

                swaps.push_back(make_pair(j, i));

                break;
            }
        }
    }

    cout << "Yes\n";

    cout << swaps.size() << "\n";

    for(int i = 0; i < swaps.size(); i++)
    {
        cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << "\n";
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

