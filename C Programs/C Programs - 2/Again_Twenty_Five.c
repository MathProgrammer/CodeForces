#include <stdio.h>
#define MAX_NUMBER_SIZE 20

int main()
{
    char power[MAX_NUMBER_SIZE];
    short final_two_digits = 25; //From n > 2  (5^n mod 100 = 25)

    scanf("%s",power);

    printf("%hu\n",final_two_digits);
    return 0;
}
