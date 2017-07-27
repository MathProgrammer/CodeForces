#include <cstdio>

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    if(no_of_elements <= 2)
        printf("-1\n");
    else
        for(int i = no_of_elements; i >= 1; i--)
            printf("%d ", i);

    return 0;
}
