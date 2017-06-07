#include <stdio.h>

#define MAX_LENGTH 150000 + 1
int heights[MAX_LENGTH];

int main()
{
    int i, no_of_planks, k, k_consecutive_sum = 0, minimum_k_consecutive_sum = 1e9, start_of_minimum_sum;
    scanf("%d %d", &no_of_planks, &k);

    for(i = 1; i <= no_of_planks; i++)
    {
        scanf("%d", &heights[i]);

        k_consecutive_sum += (i <= k ? heights[i] : heights[i] - heights[i - k]);

        if(i >= k && k_consecutive_sum <= minimum_k_consecutive_sum)
        {
            minimum_k_consecutive_sum = k_consecutive_sum;
            start_of_minimum_sum = (i - k + 1);
        }
    }

    printf("%d\n",start_of_minimum_sum);
    return 0;
}
