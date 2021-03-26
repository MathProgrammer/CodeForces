#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length, k;
    cin >> length >> k;

    string S;
    cin >> S;

    vector <int> positions;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '*')
        {
            positions.push_back(i);
        }
    }

    vector <int> changes;
    changes.push_back(positions[0]);
    for(int i = 0; i < positions.size(); i++)
    {
        if(positions[i] - changes.back() > k)
        {
            changes.push_back(positions[i - 1]);
        }

        if(i + 1 == positions.size())
        {
            if(positions[i] != changes.back())
            {
                changes.push_back(positions[i]);
            }
        }

    }

    cout << changes.size() << "\n";

}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

