#include <stdio.h>
#include <string.h>

#define SIZE_LIMIT 102 //100 + 2 extra characters

int main()
{
    char first_number[SIZE_LIMIT], last_number[SIZE_LIMIT], gcd[SIZE_LIMIT];

    scanf("%s %s",first_number, last_number);

    if(strcmp(first_number, last_number) == 0)//Stcmp return 0 if both strings are equal
    {
        strcpy(gcd,first_number); //gcd(n,n) = n
    }
    else
    {
        strcpy(gcd, "1"); //Answer is always 1 if there are atleast two numbers. Since any consecutive numbers are coprime. gcd(n, n+1) = 1
    }

    printf("%s\n", gcd);
    return 0;
}
