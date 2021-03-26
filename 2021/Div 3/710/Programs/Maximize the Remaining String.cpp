#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

void solve()
{
    string S;
    cin >> S;

    const int NO_OF_ALPHABETS = 26;
    vector < vector <int> > suffix_frequency(S.size() + 1, vector <int> (NO_OF_ALPHABETS, 0));
    for(int i = S.size() - 1; i >= 0; i--)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            suffix_frequency[i][alpha] = suffix_frequency[i + 1][alpha];
        }

        suffix_frequency[i][S[i] - 'a']++;
    }

    string answer;
    vector <int> used(NO_OF_ALPHABETS, false);
    for(int i = 0; i < S.size(); i++)
    {
        if(used[S[i] - 'a'])
        {
            continue;
        }

        while(answer.size() > 0 && suffix_frequency[i][answer.back() - 'a'] > 0 && answer.back() < S[i])
        {
            used[answer.back() - 'a'] = false;

            answer.pop_back();
        }

        answer += S[i];

        used[S[i] - 'a'] = true;
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
