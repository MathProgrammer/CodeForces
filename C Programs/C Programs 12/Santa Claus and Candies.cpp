#include <cstdio>

int main()
{
    int no_of_gifts;
    scanf("%d", &no_of_gifts);

    int no_of_people = 1;
    while(no_of_people*(no_of_people + 1) <= 2*no_of_gifts)
        no_of_people++;

    no_of_people--;

    printf("%d\n", no_of_people);
    for(int i = 1; i < no_of_people; i++)
    {
        printf("%d ", i);
        no_of_gifts -= i;
    }

    printf("%d\n", no_of_gifts); //Last person gets all remaining gifts
    return 0;
}
