#include <stdio.h>

int main()
{
    int number_of_letters, i;
    scanf("%d", &number_of_letters);

    //No letter must have the same neighbour on both the left and the right. aabbaabbaabb.... satisfies this condition
    for(i = 1; i <= number_of_letters; i = i+2)
    {
        //If n is odd, then only one letter should be printed at the end.
        if(i%4 == 1)
        {
            printf(i == number_of_letters ? "a\n" : "aa");
        }
        else
        {
            printf(i == number_of_letters ? "b\n" : "bb");
        }
    }
    return 0;
}
