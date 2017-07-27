#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_rows, no_of_columns, no_of_moves;
    scanf("%d %d %d", &no_of_rows, &no_of_columns, &no_of_moves);

    int black_square_formed_on_move = 0;

    typedef vector <int> v_int;
    vector <v_int> black_pixel(no_of_rows + 2, v_int (no_of_columns + 2, false));

    for(int move_i = 1; move_i <= no_of_moves; move_i++)
    {
        int row_i, column_i;
        scanf("%d %d", &row_i, &column_i);

        black_pixel[row_i][column_i] = true;

        if(black_square_formed_on_move == 0)
        {
            if(black_pixel[row_i - 1][column_i] && black_pixel[row_i - 1][column_i - 1] && black_pixel[row_i][column_i - 1])
            {
                black_square_formed_on_move = move_i;
            }

            if(black_pixel[row_i - 1][column_i] && black_pixel[row_i - 1][column_i + 1] && black_pixel[row_i][column_i + 1])
            {
                black_square_formed_on_move = move_i;
            }

            if(black_pixel[row_i][column_i - 1] && black_pixel[row_i + 1][column_i - 1] && black_pixel[row_i + 1][column_i])
            {
                black_square_formed_on_move = move_i;
            }

            if(black_pixel[row_i][column_i + 1] && black_pixel[row_i + 1][column_i + 1] && black_pixel[row_i + 1][column_i])
            {
                black_square_formed_on_move = move_i;
            }
        }
    }

    printf("%d\n", black_square_formed_on_move);
    return 0;
}
