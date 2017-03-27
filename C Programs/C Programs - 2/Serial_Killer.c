#include <stdio.h>
#include <string.h>
#define MAX_NAME_SIZE 11

int main()
{
    char murdered[MAX_NAME_SIZE], replacement[MAX_NAME_SIZE], person_1[MAX_NAME_SIZE], person_2[MAX_NAME_SIZE], survivor[MAX_NAME_SIZE];
    unsigned int no_of_days, i;

    scanf("%s %s",person_1, person_2);
    printf("%s %s\n", person_1, person_2);
    scanf("%u",&no_of_days);

    for(i = 0; i < no_of_days; i++)
    {
        scanf("%s %s",murdered, replacement);
        if(strcmp(murdered, person_1) == 0)
        {
            strcpy(survivor, person_2);
        }
        else
        {
            strcpy(survivor, person_1);
        }
        printf("%s %s\n", survivor, replacement);

        strcpy(person_1, survivor);
        strcpy(person_2, replacement);
    }
    return 0;
}
