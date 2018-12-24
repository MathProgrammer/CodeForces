#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_rectangles;
    scanf("%d", &no_of_rectangles);

    int possible = true;
    int last_height = 1e9;
    while(no_of_rectangles--)
    {
        int height, width;
        scanf("%d %d", &height, &width);

        int min_height = min(height, width);
        int max_height = max(height, width);

        if(max_height <= last_height)
            last_height = max_height;
        else if(min_height <= last_height)
            last_height = min_height;
        else
            possible = false;
    }

    printf(possible ? "YES\n" : "NO\n");
    return 0;
}
