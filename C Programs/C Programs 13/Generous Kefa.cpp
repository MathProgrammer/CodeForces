#include <cstdio>

#define MAX_LENGTH 100 + 2
#define NO_OF_ALPHABETS 26

int main()
{
    int no_of_balloons, no_of_people;
    char balloon_colours[MAX_LENGTH];
    scanf("%d %d %s",&no_of_balloons, &no_of_people, balloon_colours);

    int no_of_balloons_of_colour[NO_OF_ALPHABETS] = {0};
    for(int i = 0; i < no_of_balloons; i++)
    {
        no_of_balloons_of_colour[balloon_colours[i] - 'a']++;
    }

    int everyone_happy = true;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(no_of_balloons_of_colour[i] > no_of_people)
        {
            everyone_happy = false;
            break;
        }
    }

    printf(everyone_happy ? "YES\n" : "NO\n");
    return 0;
}
