
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 21;
int matches[MAX_N][MAX_N][MAX_N][MAX_N];

void solve()
{
    string A, B;
    cin >> A >> B;

    memset(matches, false, sizeof(matches));

    int max_length = 0, changes = A.size() + B.size();
    for(int length = 1; length <= min(A.size(), B.size()); length++)
    {
        for(int a_left = 0, a_right = a_left + length - 1; a_right < A.size(); a_left++, a_right++)
        {
            for(int b_left = 0, b_right = b_left + length - 1; b_right < B.size(); b_left++, b_right++)
            {
                if(length == 1)
                {
                    matches[a_left][a_right][b_left][b_right] = (A[a_left] == B[b_left]);
                }
                else
                {
                    matches[a_left][a_right][b_left][b_right] = ( (A[a_left] == B[b_left]) && (matches[a_left + 1][a_right][b_left + 1][b_right]) );
                }

                if(matches[a_left][a_right][b_left][b_right])
                {
                    max_length = length;

                    changes = (a_left) + (A.size() - 1 - a_right) + (b_left) + (B.size() - 1 - b_right);
                }
            }
        }
    }

    cout << changes << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
