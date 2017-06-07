#include <stdio.h>

int main()
{
    int no_of_vectors, total_x = 0, x, total_y = 0, y, total_z = 0, z, i;
    scanf("%d", &no_of_vectors);

    for(i = 1; i <= no_of_vectors; i++)
    {
        scanf("%d %d %d",&x, &y, &z);
        total_x += x;
        total_y += y;
        total_z += z;
    }

    printf(total_x == 0 && total_y == 0 && total_z == 0 ? "YES\n" : "NO\n");
    return 0;
}
