#include <stdio.h>
#include <stdlib.h>

void read(unsigned int *, unsigned int);
void display(short *, unsigned int);
void  make_winner_list(short *, unsigned int *,unsigned int);

int main()
{
    unsigned int no_of_tests;
    scanf("%u",&no_of_tests);

    unsigned int *no_of_vertices = malloc(no_of_tests*sizeof(unsigned int));
    short *winner = malloc(no_of_tests*sizeof(short));

    read(no_of_vertices, no_of_tests);
    make_winner_list(winner, no_of_vertices, no_of_tests);
    display(winner, no_of_tests);

    free(winner);
    free(no_of_vertices);
    return 0;
}

/*A move in the game is equivalent to deleting an edge from a graph with n vertices where there's an edge between consecutive numbers.
1-2-3...-n. There is no edge in between n and 1 because deleting it creates no new graphs.
The number of edges id v - 1, where v is the number of vertices.
The number of edges reduces by 1 in every move. If the number of edges is even (0 included), Player 2 wins.
If the number of edges is odd, Player 1 wins.*/
void  make_winner_list(short *winner, unsigned int *no_of_vertices,unsigned int no_of_tests)
{
    unsigned int i, sum_of_edges = 0;

    for(i = 0; i < no_of_tests; i++)
    {
        sum_of_edges = sum_of_edges + *(no_of_vertices + i) - 1;

        if(sum_of_edges%2 == 0)//Player 2 wins if there are an even number of edges
        {
            *(winner + i) = 2;
        }
        else//Player 1 wins if there are an odd number of edges
        {
            *(winner + i) = 1;
        }
    }
}
void read(unsigned int *no_of_vertices, unsigned int no_of_tests)
{
    unsigned int i;

    for(i = 0; i < no_of_tests; i++)
    {
            scanf("%u",(no_of_vertices + i));
    }
}

void display(short *winner, unsigned int no_of_tests)
{
    unsigned int i;

    for(i = 0; i < no_of_tests; i++)
    {
            printf("%hu\n",*(winner + i));
    }
}
