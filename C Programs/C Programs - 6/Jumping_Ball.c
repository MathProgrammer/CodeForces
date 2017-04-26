#include <stdio.h>
#include <stdlib.h>

int find_eventually_falling_bumpers(char *, int);
int main()
{
    int no_of_bumpers, no_of_bumpers_leading_to_fall;

    scanf("%d",&no_of_bumpers);

    char *bumpers = malloc((no_of_bumpers+1)*sizeof(char));
    scanf("%s",bumpers);

    no_of_bumpers_leading_to_fall = find_eventually_falling_bumpers(bumpers, no_of_bumpers);
    printf("%d\n",no_of_bumpers_leading_to_fall);
    free(bumpers);
    return 0;
}

int find_eventually_falling_bumpers(char *bumpers, int no_of_bumpers)
{
    int i, fall_count = 0;

    for(i = 0; (*(bumpers + i) == '<') && (*(bumpers + i) != '\0'); i++,fall_count++);//No of < in the beginning before the first > or end of string

    for(i = no_of_bumpers - 1; (*(bumpers + i) == '>') && ( i >= 0); i--, fall_count++);//No of > in the end before the last < or beginning of string
    return fall_count;
}
