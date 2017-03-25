#include <stdio.h>

#define true 1
#define false 0

short check_if_triangular(unsigned int);
int main()
{
    short is_triangular;
    unsigned int num;
    scanf("%u",&num);

    is_triangular = check_if_triangular(num);

    if(is_triangular)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short check_if_triangular(unsigned int num)
{
    unsigned int i;

    //Searching for the first triangular number that is not smaller than num
    for(i = 1; i*(i+1)/2 < num; i++);

    //Checking if the first triangular number greater than or equal to num is equal
    if(i*(i+1)/2 == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
