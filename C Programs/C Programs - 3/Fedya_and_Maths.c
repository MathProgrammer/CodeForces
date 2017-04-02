#include <stdio.h>
#include <string.h>
#define SIZE_LIMIT 100000

short get_answer(short, short);
int main()
{
    char number[SIZE_LIMIT];
    short answer, last_digit, second_last_digit;

    scanf("%s",number);

    last_digit = number[strlen(number) - 1] - '0'; //Getting the last digit
    second_last_digit = number[strlen(number) - 2] - '0';//Getting the second last digit

    answer = get_answer(second_last_digit, last_digit);

    printf("%hu\n",answer);
    return 0;
}

short get_answer(short second_last_digit, short last_digit)
{
    //Notice that 4^n = (5 - 1)^n = (-1)^n (mod 5), Similarly, 3 = (-2)^n (mod 5)
    if(last_digit%2 == 1)// If the number is odd, answer will always be 0.
    {
        return 0; //(1 + 2^n -2^n -1) (mod 5)
    }
    else //Powers of two mod 5 are {2, 4, 3, 1}. We are concerned with the even indices.
    {
          //(1 + 2.2^n + 1) (mod 5) = (2^{n+1} + 2) (mod 5). If n = 2 (mod 4), then the answer is 0, otherwise it is 4 from the observations above
          if( (second_last_digit*10 + last_digit)%4 == 0)
          {
              return 4;
          }
          else //n = 2(mod 4)
          {
              return 0;
          }
    }
}
