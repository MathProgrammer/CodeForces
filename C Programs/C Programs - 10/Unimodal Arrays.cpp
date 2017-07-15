#include <cstdio>

int main()
{
    bool is_unimodal = true;
    int no_of_elements, element_i, element_i_minus_1 = 0, phase = 1;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &element_i);

        if(phase == 1)
        {
            if(element_i < element_i_minus_1)//Phase 2 has only one element
                phase = 3;
            else if(element_i == element_i_minus_1)
                phase = 2;
        }
        else if(phase == 2)
        {
            if(element_i > element_i_minus_1)
                is_unimodal = false;
            else if(element_i < element_i_minus_1)
                phase = 3;
        }
        else if(phase == 3)
        {
            if(element_i >= element_i_minus_1)
                is_unimodal = false;
        }

        element_i_minus_1 = element_i;
    }

    printf(is_unimodal ? "YES\n" : "NO\n");
    return 0;
}
