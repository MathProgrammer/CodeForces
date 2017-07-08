#include <cstdio>

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    printf("%d ", no_of_elements);
    for(int i = 1; i < no_of_elements; i++)
        printf("%d ", i);

    return 0;
}
