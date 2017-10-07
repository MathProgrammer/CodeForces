#include <cstdio>

inline void swap(int &a, int &b)
{
    a = a^b; b = b^a; a = a^b;
}

inline void horizontal_rotate(int &column, int no_of_columns)
{
    column = no_of_columns + 1 - column;
}

inline void clockwise_transformation(int &row, int &column, int &no_of_rows, int &no_of_columns)
{
    int current_column = column, current_row = row;

    row = current_column;
    column = no_of_rows + 1 - current_row;

    swap(no_of_columns, no_of_rows);
}

inline void anti_clockwise_transformation(int &row, int &column, int &no_of_rows, int &no_of_columns)
{
    int current_row = row, current_column = column;

    column = current_row;
    row = no_of_columns + 1 - current_column;

    swap(no_of_columns, no_of_rows);
}

int main()
{
    int original_no_of_rows, original_no_of_columns, clockwise, horizontal, anti_clockwise, no_of_points;
    scanf("%d %d %d %d %d %d", &original_no_of_rows, &original_no_of_columns, &clockwise, &horizontal, &anti_clockwise, &no_of_points);

    clockwise %= 4;
    horizontal %= 2;
    anti_clockwise %= 4;

    while(no_of_points--)
    {
        int no_of_rows = original_no_of_rows;
        int no_of_columns = original_no_of_columns;
        int row, column;
        scanf("%d %d", &row, &column);

        for(int i = 1; i <= clockwise; i++)
            clockwise_transformation(row, column, no_of_rows, no_of_columns); //printf("%d %d\n", row, column);

        for(int i = 1; i <= horizontal; i++)
            horizontal_rotate(column, no_of_columns); //printf("%d %d\n", row, column);

        for(int i = 1; i <= anti_clockwise; i++)
            anti_clockwise_transformation(row, column, no_of_rows, no_of_columns); //printf("%d %d\n", row, column);

        printf("%d %d\n", row, column);
    }

    return 0;
}
