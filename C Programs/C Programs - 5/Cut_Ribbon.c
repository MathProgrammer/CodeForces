#include <stdio.h>
#define MAX_LENGTH 4001
#define NEGATIVE_INFINITY -4000

int max(int, int);
int find_maximum_number_of_pieces(int, int , int , int );
int main()
{
    int a, b, c, total_length, maximum_number_of_pieces;

    scanf("%d %d %d %d",&total_length, &a, &b, &c);

    maximum_number_of_pieces = find_maximum_number_of_pieces(total_length, a, b, c);
    printf("%d\n",maximum_number_of_pieces);
    return 0;
}

int find_maximum_number_of_pieces(int total_length, int a, int b, int c)
{
    int i, max_number_of_pieces[MAX_LENGTH];

    for(i = 1; i <= total_length; i++)
    {
        max_number_of_pieces[i] = NEGATIVE_INFINITY;
    }

    max_number_of_pieces[0] = 0;
    for(i =a; i <= total_length; i++)
    {
        max_number_of_pieces[i] = max(max_number_of_pieces[i],max_number_of_pieces[i-a] + 1);
    }

    for(i =b; i <= total_length; i++)
    {
        max_number_of_pieces[i] = max(max_number_of_pieces[i],max_number_of_pieces[i-b] + 1);
    }

    for(i =c; i <= total_length; i++)
    {
        max_number_of_pieces[i] = max(max_number_of_pieces[i],max_number_of_pieces[i-c] + 1);
    }

    return max_number_of_pieces[total_length];
}

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
