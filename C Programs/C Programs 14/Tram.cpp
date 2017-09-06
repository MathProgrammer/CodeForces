#include <cstdio>
#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_stops;
    scanf("%d", &no_of_stops);

    int minimum_capacity = 0, no_of_people_on_train = 0;
    for(int i = 1; i <= no_of_stops; i++)
    {
        int no_of_entries, no_of_exits;
        scanf("%d %d",&no_of_exits, &no_of_entries);

        no_of_people_on_train += (no_of_entries - no_of_exits);
        minimum_capacity = max(minimum_capacity, no_of_people_on_train);
    }

    printf("%d\n", minimum_capacity);
    return 0;
}
