#include <iostream>
#include <vector>

using namespace std;

const int BLACK = 0, WHITE = 1;

int get_colour(int x, int y)
{
    return (x + y)%2;
}

int is_inside(int i, int j, int rows, int columns)
{
    return (1 <= i && i <= rows && 1 <= j && j <= columns);
}

int get_xor_sum(vector <vector <int> > &G, int n, int colour)
{
    vector <vector <int> > counted(n + 1, vector <int> (n + 1, false));

    const int NO_OF_NEIGHBOURS = 4;
    int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1}, next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
    int xor_sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(get_colour(i, j) != colour)
            {
                continue;
            }

            int counted_neighbours = 0;
            for(int k = 0; k < NO_OF_NEIGHBOURS; k++)
            {
                int next_i = i + next_x[k], next_j = j + next_y[k];

                if(is_inside(next_i, next_j, n, n) && counted[next_i][next_j])
                {
                    counted_neighbours++;
                }
            }

            if(counted_neighbours == 0)
            {
                xor_sum ^= G[i][j];

                for(int k = 0; k < NO_OF_NEIGHBOURS; k++)
                {
                    int next_i = i + next_x[k], next_j = j + next_y[k];

                    if(is_inside(next_i, next_j, n, n))
                    {
                        counted[next_i][next_j] = true;
                    }
                }
            }
        }
    }

    return xor_sum;
}

void solve()
{
    int n;
    cin >> n;

    vector <vector <int> > grid(n + 1, vector <int> (n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int answer = get_xor_sum(grid, n, BLACK)^get_xor_sum(grid, n, WHITE);
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
