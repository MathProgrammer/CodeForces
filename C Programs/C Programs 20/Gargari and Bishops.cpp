#include <cstdio>
#include <cstring>

const int WHITE = 1, BLACK = 0, MAX_N = 2015;
int points[MAX_N][MAX_N];
long long principal_diagonal_sum[2*MAX_N];
long long secondary_diagonal_sum[2*MAX_N];

int colour(int x, int y)
{
    int sum = x + y;

    return (sum%2 == 0 ? WHITE : BLACK);
}

int get_principal_diagonal_no(int x, int y, int n)
{
    return (x - y + n);
}

int get_secondary_diagonal_no(int x, int y)
{
    return (x + y);
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(principal_diagonal_sum, 0, sizeof(principal_diagonal_sum));
    memset(secondary_diagonal_sum, 0, sizeof(secondary_diagonal_sum));

    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            scanf("%d", &points[x][y]);

            int principal_diagonal_no = get_principal_diagonal_no(x, y, n);
            int secondary_diagonal_no = get_secondary_diagonal_no(x, y);

            principal_diagonal_sum[principal_diagonal_no] += points[x][y];
            secondary_diagonal_sum[secondary_diagonal_no] += points[x][y];
        }
    }

    int white_x, white_y; long long white_best = 0;
    int black_x, black_y; long long black_best = 0;

    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            int principal_diagonal_no = get_principal_diagonal_no(x, y, n);
            int secondary_diagonal_no = get_secondary_diagonal_no(x, y);
            long long bishop_score = principal_diagonal_sum[principal_diagonal_no] + secondary_diagonal_sum[secondary_diagonal_no] - points[x][y];

            if(colour(x, y) == WHITE)
            {
                if(bishop_score >= white_best)
                {
                    white_best = bishop_score, white_x = x, white_y = y;
                }
            }
            else if(colour(x, y) == BLACK)
            {
                if(bishop_score >= black_best)
                {
                    black_best = bishop_score, black_x = x, black_y = y;
                }
            }
        }
    }

    long long best = black_best + white_best;
    printf("%I64d\n", best);
    printf("%d %d %d %d", white_x, white_y, black_x, black_y);

    return 0;
}
