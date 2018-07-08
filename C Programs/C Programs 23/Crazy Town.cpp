#include <cstdio>

int main()
{
    int start_x, start_y, end_x, end_y;
    scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);

    int no_of_lines;
    scanf("%d", &no_of_lines);

    int crossed_lines = 0;
    while(no_of_lines--)
    {
        long long a, b, c;
        scanf("%I64d %I64d %I64d", &a, &b, &c);

        long long start_side = a*start_x + b*start_y + c;
        long long end_side = a*end_x + b*end_y + c;

        if( (start_side > 0 && end_side < 0) || (start_side < 0 && end_side > 0) )
            crossed_lines++;
    }

    printf("%d\n", crossed_lines);
    return 0;
}
