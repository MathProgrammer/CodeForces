#include <cstdio>
#define abs(x) ( (x) > 0 ? (x) : -(x) )

int main()
{
    int x_1, x_2, y_1, y_2;
    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);

    int x_3, y_3, x_4, y_4;

    if(x_1 == x_2)
    {
        int distance = abs(y_1 - y_2);

        x_3 = x_1 + distance;
        y_3 = y_1;

        x_4 = x_2 + distance;
        y_4 = y_2;
    }
    else if(y_1 == y_2)
    {
        int distance = abs(x_1 - x_2);

        y_3 = y_1 + distance;
        x_3 = x_1;

        y_4 = y_2 + distance;
        x_4 = x_2;
    }
    else if(abs(x_1 - x_2) == abs(y_1 - y_2))
    {
        x_3 = x_1;
        y_3 = y_2;

        x_4 = x_2;
        y_4 = y_1;
    }
    else
    {
        printf("-1\n");
        return 0;
    }
    printf("%d %d %d %d\n", x_3, y_3, x_4, y_4);
    return 0;
}
