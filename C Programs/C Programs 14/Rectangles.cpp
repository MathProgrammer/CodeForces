#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    typedef vector <int> v_int;
    vector <v_int> rectangle(no_of_rows + 1, v_int(no_of_columns + 1));
    long long no_of_sets = 0;

    for(int row = 1; row <= no_of_rows; row++)
    {
        int no_of_blacks_in_row = 0, no_of_whites_in_row = 0;
        for(int column = 1; column <= no_of_columns; column++)
        {
            scanf("%d", &rectangle[row][column]);
            no_of_blacks_in_row += (rectangle[row][column] == 1);
        }

        no_of_whites_in_row = no_of_columns - no_of_blacks_in_row;

        long long black_sets = (1LL << no_of_blacks_in_row) - 1;
        long long white_sets = (1LL << no_of_whites_in_row) - 1;

        no_of_sets += black_sets + white_sets;
    }

    for(int column = 1; column <= no_of_columns; column++)
    {
        int no_of_blacks_in_column = 0, no_of_whites_in_column = 0;
        for(int row = 1; row <= no_of_rows; row++)
        {
            no_of_blacks_in_column += (rectangle[row][column] == 1);
        }
        no_of_whites_in_column = no_of_rows - no_of_blacks_in_column;

        long long black_sets = (1LL << no_of_blacks_in_column) - 1;
        long long white_sets = (1LL << no_of_whites_in_column) - 1;

        no_of_sets += black_sets + white_sets;
    }

    no_of_sets -= (no_of_columns*no_of_rows); //Singleton sets counted twice

    printf("%I64d\n", no_of_sets);
    return 0;
}
