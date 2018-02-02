#include <cstdio>
#include <cstring>

int main()
{
    int no_of_rows, no_of_columns, k;
    scanf("%d %d %d", &no_of_rows, &no_of_columns, &k);

    char seat[no_of_rows + 1][no_of_columns + 2];
    for(int row = 1; row <= no_of_rows; row++)
        scanf("%s", seat[row] + 1);

    int up_empty_seats[no_of_rows + 1][no_of_columns + 1];
    memset(up_empty_seats, 0, sizeof(up_empty_seats));

    int left_empty_seats[no_of_rows + 1][no_of_columns + 1];
    memset(left_empty_seats, 0, sizeof(left_empty_seats));

    for(int row = 1; row <= no_of_rows; row++)
    {
        for(int column = 1; column <= no_of_columns; column++)
        {
            up_empty_seats[row][column] = (seat[row][column] == '.' ? 1 + up_empty_seats[row - 1][column] : 0);
            left_empty_seats[row][column] = (seat[row][column] == '.' ? 1 + left_empty_seats[row][column - 1] : 0);
        }
    }

    int seatings[no_of_rows + 1][no_of_columns + 1];
    memset(seatings, 0, sizeof(seatings));

    for(int row = 1; row <= no_of_rows; row++)
    {
        for(int column = 1; column <= no_of_columns; column++)
        {
            seatings[row][column] = (up_empty_seats[row][column] >= k) + (left_empty_seats[row][column] >= k)
                                    + seatings[row - 1][column] + seatings[row][column - 1] - seatings[row - 1][column - 1];
        }
    }

    int total_seating = (k == 1 ? seatings[no_of_rows][no_of_columns]/2 : seatings[no_of_rows][no_of_columns]);

    printf("%d\n", total_seating);
    return 0;
}
