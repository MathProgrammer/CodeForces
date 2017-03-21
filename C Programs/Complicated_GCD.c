#include <stdio.h>
#include <string.h>

#define SIZE_LIMIT 102

int main()
{
    char first_number[SIZE_LIMIT], last_number[SIZE_LIMIT];

    scanf("%s %s",first_number, last_number);

    if(strcmp(first_number, last_number) == 0)//Stcmp return 0 if both strings are equal
    {
        printf("%s\n",first_number); //gcd(n,n) = n
    }
    else
    {
        printf("1\n"); //Answer is always 1 if there are atleast two numbers. Since any consecutive numbers are coprime. gcd(n, n+1) = 1
    }
    return 0;
}
