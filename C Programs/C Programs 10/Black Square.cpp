#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 100 + 5

int main()
{
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);
    char rectangle[MAX_LENGTH][MAX_LENGTH];

    int no_of_black_squares = 0, left_most = no_of_columns + 1, right_most = -1, highest = -1, lowest = no_of_rows + 1;

    for(int i = 0; i < no_of_rows; i++)
    {
        scanf("%s", rectangle[i]);

        for(int j = 0; j < no_of_columns; j++)
        {
            if(rectangle[i][j] == 'B')
            {
                no_of_black_squares ++;

                left_most = min(left_most, j);
                right_most = max(right_most, j);

                highest = max(highest, i);
                lowest = min(lowest, i);
            }
        }
    }

    int square_rows = highest - lowest + 1, square_columns = right_most - left_most + 1;
    int square_side = max(square_columns, square_rows);
    int repainted = -1;

    if(no_of_black_squares == 0)
    {
        repainted = 1;
    }
    else if(square_side <= min(no_of_rows, no_of_columns))
    {
        repainted = square_side*square_side - no_of_black_squares;
    }

    printf("%d\n", repainted);
    return 0;
}
