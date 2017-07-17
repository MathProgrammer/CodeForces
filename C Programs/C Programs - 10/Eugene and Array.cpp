#include <cstdio>

int main()
{
    int no_of_elements, no_of_queries, no_of_1 = 0, no_of_minus_1 = 0;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        no_of_1 += (element_i == 1);
        no_of_minus_1 += (element_i == -1);
    }

    for(int i = 1; i <= no_of_queries; i++)
    {
        int left, right, range;
        scanf("%d %d", &left, &right);

        range = right - (left - 1);
        printf(range%2 == 0 && no_of_1 >= range/2 && no_of_minus_1 >= range/2 ? "1\n" : "0\n");
    }

    return 0;
}
