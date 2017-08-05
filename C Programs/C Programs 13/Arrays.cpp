#include <cstdio>

int main()
{
    int size_a, size_b;
    scanf("%d %d", &size_a, &size_b);

    int last_a, first_b, last_a_position, first_b_position;
    scanf("%d %d", &last_a_position, &first_b_position);

    int element_i;
    for(int i = 1; i <= size_a; i++)
    {
        scanf("%d", &element_i);
        if(i == last_a_position)
            last_a = element_i;
    }

    for(int i = size_b; i >= 1; i--)
    {
        scanf("%d", &element_i);
        if(i == first_b_position)
            first_b = element_i;
    }

    printf(last_a < first_b ? "YES\n" : "NO\n");
    return 0;
}
