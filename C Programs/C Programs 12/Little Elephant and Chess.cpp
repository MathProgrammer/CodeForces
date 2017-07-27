#include <cstdio>

#define NO_OF_COLUMNS 8

int main()
{
    const int no_of_rows = 8;
    bool all_rows_have_alternating_colours = true;

    for(int i = 1; i <= no_of_rows; i++)
    {
        char row[NO_OF_COLUMNS + 2];
        scanf("%s", row);

        for(int square = 1; row[square] != '\0'; square++)
        {
            if(row[square] ==row[square - 1])
            {
                all_rows_have_alternating_colours = false;
            }
        }
    }

    printf(all_rows_have_alternating_colours ? "YES\n" : "NO\n");
    return 0;
}
