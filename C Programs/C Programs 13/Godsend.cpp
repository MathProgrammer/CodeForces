#include <cstdio>

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int only_even_numbers = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        if(element_i%2 == 1)
            only_even_numbers = false;
    }

    printf(only_even_numbers ? "Second\n" : "First\n");
    return 0;
}
