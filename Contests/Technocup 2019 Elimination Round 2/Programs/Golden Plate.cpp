#include <cstdio>

int main()
{
    int rows, columns, k;
    scanf("%d %d %d", &rows, &columns, &k);

    int total_perimeter = 0;
    int r = rows, c = columns;
    for(int i = 1; i <= k; i++)
    {
        int perimeter = 2*r + 2*c - 4;

        total_perimeter += perimeter;

        r -= 4;
        c -= 4;
    }

    printf("%d\n", total_perimeter);
    return 0;
}
