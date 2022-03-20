#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    string S;
    cin >> S;

    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency(NO_OF_ALPHABETS + 1, 0);
    for(int i = 0; i < S.size(); i++)
    {
        frequency[S[i] - 'a']++;
    }

    int start = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(frequency[S[i] - 'a'] == 1)
        {
            start = i;
            break;
        }

        frequency[S[i] - 'a']--;
    }

    string answer;
    for(int i = start; i < S.size(); i++)
    {
        answer += S[i];
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

