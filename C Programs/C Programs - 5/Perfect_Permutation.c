#include <stdio.h>
void display_perfect_permutation(unsigned int);
int main()
{
    unsigned int no_of_elements;
    scanf("%u",&no_of_elements);
    display_perfect_permutation(no_of_elements);
    return 0;
}

/*If p(i) = i, then it is clearly a perfect permutation.

Since, this is not allowed, we swap adjacent values p(2k) = 2k+ 1 and p(2k + 1) = 2k
So, an answer is available for all even n.

Since, p(p(i)) = i, every time we change the value of p(i), we must also change the p(i) accordingly. Values have to get changed in pairs. Swapping adjacent values
does the trick.

However, if there are an odd number of elements, the last element will not have any number to get swapped with and will satisfy p(i) = i.
So, there is no perfect permutation for odd i.*/

void display_perfect_permutation(unsigned int no_of_elements)
{
    unsigned int i;
    if(no_of_elements%2 == 1)
    {
        printf("-1\n");
    }
    else
    {
        for(i = 1; i < no_of_elements; i = i + 2)
        {
            printf("%u %u ",(i + 1), i);
        }
    }
}
