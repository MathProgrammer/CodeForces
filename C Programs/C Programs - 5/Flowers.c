#include <stdio.h>
#include <stdlib.h>

void read(int , int *, int *, int *);
void find_no_of_possible_meals(unsigned long long*, int, int);
void find_sum_possible_meals(unsigned long long*, unsigned long long*, int);
void display_answer(int *, int *, unsigned long long*, int);

const long long MOD = 1e9 + 7;

int main()
{
    int no_of_test_cases, consecutive_flower_length, maximum_length;
    scanf("%u %u", &no_of_test_cases, &consecutive_flower_length);

    int *starting_length = malloc(no_of_test_cases*sizeof(int));
    int *final_length = malloc(no_of_test_cases*sizeof(int));

    read(no_of_test_cases, starting_length, final_length, &maximum_length);

    unsigned long long*no_of_meals = malloc((maximum_length + 1)*sizeof(unsigned long long));
    unsigned long long*sum_no_of_meals =  malloc((maximum_length + 1)*sizeof(unsigned long long));
    find_no_of_possible_meals(no_of_meals, maximum_length, consecutive_flower_length);
    find_sum_possible_meals(sum_no_of_meals, no_of_meals, maximum_length);

    display_answer(starting_length, final_length, sum_no_of_meals, no_of_test_cases);

    free(no_of_meals);
    free(sum_no_of_meals);
    free(starting_length);
    free(final_length);
    return 0;
}

void read(int no_of_test_cases, int *starting_length, int *final_length, int *maximum_length)
{
    int i;
    *maximum_length = 0;
    for(i = 0; i < no_of_test_cases; i++)
    {
        scanf("%d %d", (starting_length + i), (final_length + i));
        if(*maximum_length < *(final_length + i) )
        {
            *maximum_length = *(final_length + i);
        }
    }
}

void find_no_of_possible_meals(unsigned long long *no_of_meals, int maximum_length, int consecutive_flower_length)
{
    int i;

    //f(x) = f(x-1) + f(x-k) ... If the first flower is red remaining can be in any way,if the first is white, then the next k-1 are forced to be white
    for(i = 0; i <= maximum_length; i++)
    {
        if(i < consecutive_flower_length)
        {
            *(no_of_meals + i) = 1;
        }
        else
        {
            *(no_of_meals + i) = *(no_of_meals + i - 1) + *(no_of_meals + i - consecutive_flower_length);
            *(no_of_meals + i) = *(no_of_meals + i)%MOD;
        }
        //printf("Meal %d = %lu\n",i,*(no_of_meals + i) );
    }
}

void find_sum_possible_meals(unsigned long long*sum_no_of_meals, unsigned long long*no_of_meals, int maximum_length)
{
    int i;

    *(sum_no_of_meals + 0) = 0;
    for(i = 1; i <= maximum_length; i++)
    {
        *(sum_no_of_meals + i) = (*(sum_no_of_meals + i - 1) + *(no_of_meals + i));
        *(sum_no_of_meals + i) = *(sum_no_of_meals + i)%MOD;
        //printf("Sum Meal %d = %lu\n",i,*(sum_no_of_meals + i) );
    }
}

void display_answer(int *starting_length, int *final_length, unsigned long long*sum_no_of_meals, int no_of_test_cases)
{
    int i, min_no_of_flowers, max_no_of_flowers;
    unsigned long long max_no_of_meals, min_no_of_meals, total_meals;

    for(i = 0; i < no_of_test_cases; i++)
    {
        max_no_of_flowers =  *(final_length + i) ;
        min_no_of_flowers = *(starting_length + i) - 1;
        max_no_of_meals = *(sum_no_of_meals + max_no_of_flowers); //printf("Max = %I64u\n",max_no_of_meals);
        min_no_of_meals = *(sum_no_of_meals + min_no_of_flowers); //printf("Min = %I64u\n",min_no_of_meals);

        total_meals = (max_no_of_meals - min_no_of_meals + MOD)%MOD;
        printf("%I64u\n", total_meals);
    }
}
