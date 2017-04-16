#include <stdio.h>

#define INFINITY 1e5 + 1
int abs(int);
int find_longest_subsequence_odd_sum(int);

int main()
{
    int no_of_elements, longest_odd_subsequence_sum;
    scanf("%d",&no_of_elements);

    longest_odd_subsequence_sum = find_longest_subsequence_odd_sum(no_of_elements);
    printf("%d\n",longest_odd_subsequence_sum);
    return 0;
}

int find_longest_subsequence_odd_sum(int no_of_elements)
{
    int number, sum = 0, odd_min = INFINITY, i;

    /*Find the sum of all positive numbers. Keep track of the minimum |x| such that x is odd.
      If the sum we get is odd, return the sum.
      Else - the minimum absolute odd number may be odd or even.
      If it is positive, we delete it from the chosen subsequence. Sum becomes sum - x
      If it is negative, we add it to the subsequence, Sum becomes sum + x = sum - abs(x)
      In one line, we can write, sum = sum - abs(x)*/
    for(i = 0; i < no_of_elements; i++)
    {
        scanf("%d",&number);
        if(number > 0)
        {
            //Only adding positive numbers
            sum = sum + number;
        }

        if(abs(number) % 2 == 1)
        {
            //We want the smallest odd number. If it is positive, we remove it from the sum. If it is negative we add it to the sum, in case sum is even
            odd_min = (abs(number) < odd_min ? abs(number) : odd_min);
        }
    }

    //Returning sum if it is odd. Else, if sum is even, we subtract the smallest odd number so that it's sum is still odd
    return (sum%2 == 1 ? sum : (sum - abs(odd_min)) );
}

int abs(int a)
{
    return (a > 0 ? a : -a);
}
