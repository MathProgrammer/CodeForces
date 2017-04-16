#include <stdio.h>

#define MAX_LENGTH 100000 + 1

void read_frequency(int [], int, int *);
long long max(long long ,long long);
long long find_maximum_score(int [], int);

int main()
{
    int frequency[MAX_LENGTH]= {0}, no_of_numbers, max_in_array = 0;
    long long maximum_score;
    scanf("%d",&no_of_numbers);

    read_frequency(frequency, no_of_numbers, &max_in_array);
    maximum_score = find_maximum_score(frequency, max_in_array);
    printf("%I64d\n",maximum_score);
    return 0;
}

long long find_maximum_score(int frequency[],int max_in_array)
{
    int i;
    long long maximum_score_i_minus_2 = 0, maximum_score_i_minus_1 = frequency[1], maximum_score_i  = frequency[1];

    /*Let f(i) be the greatest score possible where all numbers upto i are deleted.
      There are two options - Either we delete i by selecting it - f(i-2) + frequency[i]*i.
	  Or we delete it by selecting i-1 - f(i-1)
        i = 2 to 10^5
       f(i) = max{f(i-1), f(i-2) + i*frequency[i]}*/
    for(i = 2; i <= 1e5; i++)
    {
        maximum_score_i = max(maximum_score_i_minus_1, maximum_score_i_minus_2 + frequency[i]*1LL*i);

        maximum_score_i_minus_2 = maximum_score_i_minus_1;
        maximum_score_i_minus_1 = maximum_score_i;
    }

    return maximum_score_i;
}

void read_frequency(int frequency[], int no_of_numbers, int *max_in_array)
{
    int i, current_number;

    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%d",&current_number);
        frequency[current_number]++;
        *max_in_array = max(*max_in_array, current_number);
    }
}

long long max(long long a, long long b)
{
    return (a > b ? a : b);
}
