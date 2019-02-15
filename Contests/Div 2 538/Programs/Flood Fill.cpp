#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
const int MAX_N = 5005, oo = 5005;
int minimum_moves[MAX_N][MAX_N][2];

int main()
{
    int no_of_squares;
    cin >> no_of_squares;

    vector <int> A(no_of_squares + 1);
    for(int i = 1; i <= no_of_squares; i++)
        cin >> A[i];

    for(int i = 1; i <= no_of_squares; i++)
    {
        for(int j = i; j <= no_of_squares; j++)
        {
            for(int direction = 0; direction < 2; direction++)
            {
                minimum_moves[i][j][direction] = (i == j ? 0 : oo);
            }
        }
    }

    for(int length = 2; length <= no_of_squares; length++)
    {
        for(int left = 1, right = left + length - 1; right <= no_of_squares; left++, right++)
        {
            for(int direction = 0; direction < 2; direction++)
            {
                int current = (direction == 0 ? A[left + 1] : A[right]);

                minimum_moves[left][right][0] = min(minimum_moves[left][right][0],
                                                    minimum_moves[left + 1][right][direction] + (A[left] != current));
            }

            for(int direction = 0; direction < 2; direction++)
            {
                int current = (direction == 0 ? A[left] : A[right - 1]);

                minimum_moves[left][right][1] = min(minimum_moves[left][right][1],
                                                    minimum_moves[left][right - 1][direction] + (current != A[right]));
            }
        }
    }

    LL answer = min(minimum_moves[1][no_of_squares][0], minimum_moves[1][no_of_squares][1]);
    cout << answer;

    return 0;
}
