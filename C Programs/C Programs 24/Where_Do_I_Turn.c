#include <stdio.h>

int main()
{
    int a_x, a_y, b_x, b_y, c_x, c_y;
    scanf("%d %d %d %d %d %d", &a_x, &a_y, &b_x, &b_y, &c_x, &c_y);

    //Cross_product
    if( (c_y - b_y)*1LL*(b_x - a_x) - (b_y - a_y)*1LL*(c_x - b_x) == 0 )
        printf("TOWARDS\n");
    else if( (c_y - b_y)*1LL*(b_x - a_x) - (b_y - a_y)*1LL*(c_x - b_x) > 0 )
        printf("LEFT\n");
    else
        printf("RIGHT\n");
    return 0;
}
