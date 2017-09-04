#include <cstdio>

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int first_or_last_element_even = false;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        if(i == 1 || i == no_of_elements)
            if(element_i%2 == 0)
                first_or_last_element_even = true;
    }

    printf(no_of_elements%2 == 0 || first_or_last_element_even ? "No\n" : "Yes\n");
    return 0;
}
