#include <cstdio>

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        sum += element_i;
    }

    printf("%d\n", sum%no_of_elements == 0 ? no_of_elements : no_of_elements - 1);
    return 0;
}
