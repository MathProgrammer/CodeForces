#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
const int MAX_N = 5005, oo = 5005, LEFT_COLOUR = 0, RIGHT_COLOUR = 1, NO_OF_ENDS = 2;
int minimum_moves[MAX_N][MAX_N][NO_OF_ENDS];

int main()
{
    int no_of_squares;
    cin >> no_of_squares;

    vector <int> A(no_of_squares + 1);
    for(int i = 1; i <= no_of_squares; i++)
        cin >> A[i];

    for(int i = 1; i <= no_of_squares; i++)
    {
        minimum_moves[i][i][LEFT_COLOUR] = minimum_moves[i][i][RIGHT_COLOUR] = 0;
    }

    for(int length = 2; length <= no_of_squares; length++)
    {
        for(int left = 1, right = left + length - 1; right <= no_of_squares; left++, right++)
        {
            minimum_moves[left][right][LEFT_COLOUR] = min(minimum_moves[left + 1][right][LEFT_COLOUR] + (A[left] != A[left + 1]),
                                                          minimum_moves[left + 1][right][RIGHT_COLOUR] + (A[left] != A[right]));

            minimum_moves[left][right][RIGHT_COLOUR] = min(minimum_moves[left][right - 1][LEFT_COLOUR] + (A[left] != A[right]),
                                                           minimum_moves[left][right - 1][RIGHT_COLOUR] + (A[right - 1] != A[right]));
        }
    }

    LL answer = min(minimum_moves[1][no_of_squares][LEFT_COLOUR], minimum_moves[1][no_of_squares][RIGHT_COLOUR]);
    cout << answer;

    return 0;
}
