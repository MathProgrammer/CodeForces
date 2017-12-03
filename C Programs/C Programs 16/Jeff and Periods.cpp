#include <cstdio>

const int NOT_POSSIBLE = -1, MAX_ELEMENTS = 1e5 + 1;

struct number
{
    int last_index, second_last_index, difference;

    number(){ last_index = second_last_index = 0; difference = NOT_POSSIBLE;}
};

int main()
{
    number elements[MAX_ELEMENTS];

    int no_of_elements;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int n;
        scanf("%d", &n);

        if(elements[n].last_index == 0)
        {
            elements[n].last_index = i;
            elements[n].difference = 0;
        }
        else if(elements[n].second_last_index == 0)
        {
            elements[n].second_last_index = elements[n].last_index;
            elements[n].last_index = i;
            elements[n].difference = elements[n].last_index - elements[n].second_last_index;
        }
        else
        {
            if(i - elements[n].last_index == elements[n].difference)
            {
                elements[n].second_last_index = elements[n].last_index;
                elements[n].last_index = i;
            }
            else
            {
                elements[n].difference = NOT_POSSIBLE;
            }
        }
    }

    int no_of_aps = 0;
    for(int i = 1; i < MAX_ELEMENTS; i++)
        no_of_aps += (elements[i].difference != NOT_POSSIBLE);

    printf("%d\n", no_of_aps);
    for(int i = 1; i < MAX_ELEMENTS; i++)
        if(elements[i].difference != NOT_POSSIBLE)
            printf("%d %d\n", i, elements[i].difference);

    return 0;
}
