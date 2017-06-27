#include <stdio.h>

int main()
{
    long long nearest_end, position, i;
    scanf("%I64d", &position);

    i = 0;
    while(i*(i + 1)/2 < position)
        i++;

    i--;
    nearest_end = i*(i + 1)/2 ;

    printf("%I64d\n",(position - nearest_end));

    return 0;
}
