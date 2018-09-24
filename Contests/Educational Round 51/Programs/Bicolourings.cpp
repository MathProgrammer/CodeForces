#include <cstdio>
#include <cstring>

const int NO_OF_COLUMN_ARRANGEMENTS = 4, MAX_N = 1005;
const int MOD = 998244353;
const int BB = 0, BW = 1, WB = 2, WW = 3;

typedef long long LL;
LL no_of_ways[MAX_N][2*MAX_N][NO_OF_COLUMN_ARRANGEMENTS];

int additional_components(int second_last, int last)
{
    switch(second_last)
    {
        case BB : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 1;
                      case WB : return 1;
                      case WW : return 1;
                  }
        case BW : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 0;
                      case WB : return 2;
                      case WW : return 0;
                  }
        case WB : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 2;
                      case WB : return 0;
                      case WW : return 0;
                  }
        case WW : switch(last)
                  {
                      case BB : return 1;
                      case BW : return 1;
                      case WB : return 1;
                      case WW : return 0;
                  }
    }
}

int main()
{
    int no_of_columns, no_of_components;
    scanf("%d %d", &no_of_columns, &no_of_components);

    memset(no_of_ways, 0, sizeof(no_of_ways));
    no_of_ways[1][1][BB] = no_of_ways[1][1][WW] = 1;
    no_of_ways[1][2][BW] = no_of_ways[1][2][WB] = 1;

    for(int column = 2; column <= no_of_columns; column++)
    {
        for(int components = 1; components <= 2*no_of_columns; components++)
        {
            for(int last = 0; last < NO_OF_COLUMN_ARRANGEMENTS; last++)
            {
                for(int second_last = 0; second_last < NO_OF_COLUMN_ARRANGEMENTS; second_last++)
                {
                    int new_components = components + additional_components(second_last, last);

                    no_of_ways[column][new_components][last] += no_of_ways[column - 1][components][second_last];

                    no_of_ways[column][new_components][last] %= MOD;
                }
            }
        }
    }

    LL answer = 0;
    for(int last = 0; last < NO_OF_COLUMN_ARRANGEMENTS; last++)
    {
        answer += no_of_ways[no_of_columns][no_of_components][last];

        answer %= MOD;
    }

    printf("%I64d\n", answer);
    return 0;
}
