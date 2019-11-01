#include <iostream>

using namespace std;

const int MAX_N = 105;
char board[MAX_N][MAX_N];

int main()
{
    int n;
    cin >> n;

    board[1][1] = 'B'; board[1][2] = 'W';
    board[2][1] = 'W'; board[2][2] = 'B';

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i <= 2 && j <= 2)
            {
                continue;
            }

            if(j <= 2)
            {
                board[i][j] = (board[i - 2][j - 1] == 'B' ? 'W' : 'B');

                continue;
            }

            board[i][j] = (board[i - 1][j - 2] == 'B' ? 'W' : 'B');
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << board[i][j];
        }

        cout << "\n";
    }

    return 0;
}
