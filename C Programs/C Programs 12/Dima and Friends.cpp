#include <cstdio>

int main()
{
    int no_of_friends;
    scanf("%d", &no_of_friends);

    int other_fingers = 0;
    for(int i = 1; i <= no_of_friends; i++)
    {
        int finger_i;
        scanf("%d", &finger_i);

        other_fingers += finger_i;
    }

    const int NO_OF_FINGERS = 5;
    int no_of_choices = 0, no_of_people = no_of_friends + 1;

    for(int dima_fingers = 1; dima_fingers <= NO_OF_FINGERS; dima_fingers++)
    {
        int total_fingers = other_fingers + dima_fingers;
        no_of_choices += (total_fingers%no_of_people != 1); //choice is valid only if total =/= 1 mod no of people
    }

    printf("%d\n", no_of_choices);
    return 0;
}
