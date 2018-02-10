#include <cstdio>
#define NO_OF_STRIPS 100000 + 2

int main()
{
    int no_of_strips;
    char strip[NO_OF_STRIPS];
    scanf("%d %s", &no_of_strips, strip);

    int jump[no_of_strips + 1];
    int visited[no_of_strips + 1] = {false};

    for(int i = 0; i < no_of_strips; i++)
        scanf("%d", &jump[i]);

    int square = 0, stuck_forever;

    while(true)
    {
        if(visited[square] == true)
        {
            stuck_forever = true;
            break;
        }

        visited[square] = true;

        if(strip[square] == '<')
        {
            if(square - jump[square] < 0)
            {
                stuck_forever = false;
                break;
            }

            square -= jump[square];
        }
        else
        {
            if(square + jump[square] >= no_of_strips)
            {
                stuck_forever = false;
                break;
            }

            square += jump[square];
        }
    }

    printf(stuck_forever ? "INFINITE\n" : "FINITE\n");
    return 0;
}
