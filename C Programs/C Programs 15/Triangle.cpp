#include <cstdio>

int triangle(int side_a, int side_b, int side_c)
{
    return ( (side_a + side_b > side_c) && (side_b + side_c > side_a) && (side_c + side_a > side_b) );
}

int segment(int side_a, int side_b, int side_c)
{
    return ( (side_a + side_b == side_c) || (side_b + side_c == side_a) || (side_c + side_a == side_b) );
}

int main()
{
    int side_a, side_b, side_c, side_d;
    scanf("%d %d %d %d", &side_a, &side_b, &side_c, &side_d);

    if(triangle(side_a, side_b, side_c) || triangle(side_b, side_c, side_d) || triangle(side_c, side_d, side_a) || triangle(side_b, side_a, side_d) )
        printf("TRIANGLE\n");
    else if(segment(side_a, side_b, side_c) || segment(side_b, side_c, side_d) || segment(side_c, side_d, side_a) || segment(side_b, side_a, side_d) )
        printf("SEGMENT\n");
    else
        printf("IMPOSSIBLE\n");

    return 0;
}
