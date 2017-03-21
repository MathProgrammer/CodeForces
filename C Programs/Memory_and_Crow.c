#include <stdio.h>
#include <stdlib.h>

void get_crow_answer(long *, long);
void get_original_series(long *, long *, long);
void display_original_series(long *,long);
int main()
{
    long no_of_numbers;

    scanf("%ld",&no_of_numbers);

    long *crow_answer = malloc(no_of_numbers*sizeof(long));
    long *original_series = malloc(no_of_numbers*sizeof(long));

    get_crow_answer(crow_answer, no_of_numbers);
    get_original_series(crow_answer, original_series, no_of_numbers);
    display_original_series(original_series, no_of_numbers);

    free(crow_answer);
    free(original_series);
    return 0;
}

void get_crow_answer(long *crow_answer, long no_of_numbers)
{
    long i;

    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%lu",(crow_answer + i));
        //printf("%ld\t",*(crow_answer + i));
    }
}

void get_original_series(long *crow_answer, long *original_series, long no_of_numbers)
{
    long i;

    //B(n) = A(n) For all other i != n, B[i] = A[i] + A[i+1]
    *(original_series + no_of_numbers - 1) = *(crow_answer + no_of_numbers - 1);
    for(i = no_of_numbers - 2; i >= 0; i--)
    {
            *(original_series + i) = *(crow_answer + i) + *(crow_answer + i + 1);
            //printf("%ld\t",*(original_series + i));
    }
}

void display_original_series(long *original_series, long no_of_numbers)
{
    long i;

    for(i = 0; i < no_of_numbers; i++)
    {
        printf("%ld\t",*(original_series + i));
    }
}
