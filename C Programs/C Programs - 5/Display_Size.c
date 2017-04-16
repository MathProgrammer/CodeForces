#include <stdio.h>
#include <math.h>

int main()
{
    int no_of_pixels, no_of_rows, no_of_columns;
    scanf("%d",&no_of_pixels);

    for(no_of_rows = (int) sqrt(no_of_pixels) ;no_of_rows > 0; no_of_rows--)
    {
        if(no_of_pixels%no_of_rows == 0)
        {
            break;
        }
    }
    no_of_columns = no_of_pixels/no_of_rows;
    printf("%d %d\n",no_of_rows, no_of_columns);
    return 0;
}
