#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ROWS 5
#define NO_OF_COLUMNS 5

void read_matrix(short[][NO_OF_COLUMNS],short*, short*);
short find_no_of_moves_to_centralise_1(short, short, short, short);

int main()
{
    short matrix[NO_OF_ROWS][NO_OF_COLUMNS], row_of_1, column_of_1, no_of_moves_to_centralise_1;

    read_matrix(matrix, &row_of_1, &column_of_1); //Passing row of 1 and columns of 1 by reference
    no_of_moves_to_centralise_1 = find_no_of_moves_to_centralise_1(NO_OF_ROWS, NO_OF_COLUMNS,row_of_1, column_of_1);
    printf("%hu\n",no_of_moves_to_centralise_1);
    return 0;
}

void read_matrix(short matrix[][NO_OF_COLUMNS], short *row_of_1, short *column_of_1) //Here, row of 1 and column of 1 are pointers
{
    short i, j;

    for(i = 0; i <NO_OF_ROWS; i++)
    {
        for(j = 0; j < NO_OF_COLUMNS; j++)
        {
            scanf("%hu", &matrix[i][j]);

            if(matrix[i][j] == 1)
            {
                *(row_of_1) = i; //Dereference operator to store the value at the address held by the pointer
                *(column_of_1) = j;
            }
        }
    }
}

short find_no_of_moves_to_centralise_1(short no_of_rows, short no_of_columns, short row_of_1, short column_of_1)
{
    short row_moves, column_moves, total_moves;

    row_moves = abs(row_of_1 - no_of_rows/2);
    column_moves = abs(column_of_1 - no_of_columns/2);
    total_moves = row_moves + column_moves;

    return total_moves;
}
