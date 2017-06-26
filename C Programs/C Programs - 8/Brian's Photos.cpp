#include <stdio.h>

int main()
{
    bool is_colourful = false;
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    for(int row = 1; row <= no_of_rows; row++)
    {
        for(int column = 1; column <= no_of_columns; column++)
        {
            char colour;
            scanf(" %c", &colour);

            if(colour != 'B' && colour != 'G' && colour != 'W')
                is_colourful = true;
        }
    }

    printf(is_colourful ? "#Color\n" : "#Black&White\n");
    return 0;
}
