#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_problems;
    cin >> no_of_problems;

    vector <int> tag(no_of_problems + 1), score(no_of_problems + 1);
    for(int i = 1; i <= no_of_problems; i++)
    {
        cin >> tag[i];
    }

    for(int i = 1; i <= no_of_problems; i++)
    {
        cin >> score[i];
    }

    vector <long long> score_ending_at(no_of_problems + 1);
    for(int i = 1; i <= no_of_problems; i++)
    {
        for(int j = i - 1; j > 0; j--)
        {
            if(tag[i] == tag[j])
            {
                continue;
            }

            long long current_i = score_ending_at[i], current_j = score_ending_at[j], score_here = abs(score[i] - score[j]);

            score_ending_at[i] = max(score_ending_at[i], current_j + score_here);
            score_ending_at[j] = max(score_ending_at[j], current_i + score_here);
        }
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_problems; i++)
    {
        answer = max(answer, score_ending_at[i]);
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
