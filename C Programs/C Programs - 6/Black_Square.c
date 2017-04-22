#include <stdio.h>

#define MAX_LENGTH 100001
int main()
{
    int calories[5],total_calories = 0, i;
    char game[MAX_LENGTH];

    for(i = 1; i <= 4; i++) //For convenience start the array index from 1-4, because the string also contains elements from 1-4
    {
        scanf("%d", &calories[i]);
    }
    scanf("%s",game);

    for(i = 0; game[i] != '\0'; i++)
    {
        total_calories += calories[game[i] - '0'];
    }

    printf("%d\n",total_calories);
    return 0;
}
