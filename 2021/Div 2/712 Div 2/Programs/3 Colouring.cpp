#include <iostream>
#include <vector>

using namespace std;

void display(vector <vector <int> > &grid)
{
    for(int i = 1; i < grid.size(); i++)
    {
        for(int j = 1; j < grid.size(); j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

pair <int, int> colour(vector <vector <int> > &grid, int n, int parity, int col)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if( (i + j)%2 == parity && grid[i][j] == 0)
            {
                grid[i][j] = col;

                return make_pair(i, j);
            }
        }
    }

    return make_pair(0, 0);
}

int main()
{
    int n;
    cin >> n;

    const int BLACK = 1, WHITE = 2, RED = 3;
    int available_even =(n*n)/2 + ((n*n)%2 == 1 ? 1 : 0), available_odd = (n*n)/2;

    vector <vector <int> > grid(n + 1, vector <int> (n + 1, 0));
    for(int i = 1; i <= n*n; i++)
    {
        int alice_colour;
        cin >> alice_colour;

        int bob_colour;

        int parity = (i%2);

        pair <int, int> P;

        switch(alice_colour)
        {
            case BLACK : if(available_odd > 0)
                         {
                            bob_colour = WHITE;
                            P = colour(grid, n, 1, WHITE);
                            available_odd--;
                         }
                         else
                         {
                             bob_colour = RED;
                             P = colour(grid, n, 0, RED);
                             available_even--;
                         }
                         break;

            case WHITE : if(available_even > 0)
                         {
                            bob_colour = BLACK;
                            P = colour(grid, n, 0, BLACK);
                            available_even--;
                         }
                         else
                         {
                             bob_colour = RED;
                             P = colour(grid, n, 1, RED);
                             available_odd--;
                         }
                         break;

            case RED : if(available_even > 0)
                       {
                            bob_colour = BLACK;
                            P = colour(grid, n, 0, BLACK);
                            available_even--;
                       }
                       else
                       {
                           bob_colour = WHITE;
                           P = colour(grid, n, 1, WHITE);
                           available_odd--;
                       }
        }

        cout << bob_colour << " " << P.first << " " << P.second << "\n";
        cout.flush(); //display(grid);
    }

    return 0;
}
