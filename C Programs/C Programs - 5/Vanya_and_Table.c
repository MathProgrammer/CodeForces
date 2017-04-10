#include <stdio.h>
unsigned int count_cells_covered(unsigned int);
int main()
{
    unsigned int no_of_rectangles, total_cells_counted;
    scanf("%u",&no_of_rectangles);
    total_cells_counted = count_cells_covered(no_of_rectangles);
    printf("%u\n",total_cells_counted);
    return 0;
}

unsigned int count_cells_covered(unsigned int no_of_rectangles)
{
    unsigned int i, x1, x2, y1, y2, no_of_cells_counted = 0;

    for(i = 0; i < no_of_rectangles; i++)
    {
        scanf("%u %u %u %u", &x1, &y1, &x2, &y2);
        no_of_cells_counted = no_of_cells_counted + (x2 - x1 + 1)*(y2 - y1 + 1); //This is the number of cells in the current rectangle. The last
        //cell has a point (x2 + 1, y2 + 1). We want to count it as well.
    }
    return no_of_cells_counted;
}
