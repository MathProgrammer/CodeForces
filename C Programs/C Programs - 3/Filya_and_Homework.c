#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

short count_no_of_distinct_elements(unsigned long *,unsigned long, unsigned long[]);
short check_if_set_is_in_AP(unsigned long[], short);
void get_answer(char[], short);

int main()
{
    short is_possible = false, distinct_count;
    unsigned long no_of_elements, i, distinct_element[3];
    unsigned long *list_of_numbers = NULL;
    char answer[4];

    scanf("%lu",&no_of_elements);
    list_of_numbers = malloc(no_of_elements*sizeof(unsigned long));
    for(i = 0; i < no_of_elements; i++)
    {
        scanf("%lu",(list_of_numbers + i));
    }


    distinct_count = count_no_of_distinct_elements(list_of_numbers, no_of_elements, distinct_element);

    if(distinct_count > 3)
    {
        is_possible = false;
    }
    else
    {
        is_possible = check_if_set_is_in_AP(distinct_element, distinct_count);
    }
    get_answer(answer, is_possible);

    printf("%s\n",answer);
    free(list_of_numbers);
    return 0;
}

short count_no_of_distinct_elements(unsigned long *list_of_numbers,unsigned long no_of_elements, unsigned long distinct_element[])
{
    short distinct_count = 0, already_counted;
    int i, j;

    for(i = 0; i < no_of_elements; i++)
    {
        already_counted = false; //For the i=th element,
        for(j = 0; j < distinct_count ; j++)
        {
            if(*(list_of_numbers + i) == distinct_element[j])
            {
                already_counted = true;
                break;
            }
        }
        if(already_counted == false)
        {
            distinct_element[distinct_count] = *(list_of_numbers + i);
            distinct_count++;
            if(distinct_count > 3) //If it exceeds three, just stop. Because it isn't possible for more than three distinct elements.
            {
                break;
            }
        }
    }
    return distinct_count ;
}

short check_if_set_is_in_AP(unsigned long distinct_element[], short distinct_count)
{
    short set_is_in_AP = false;

    if(distinct_count < 3) //Set of 2 or 1 element will always be in AP
    {
        set_is_in_AP = true;
        return set_is_in_AP;
    }

    unsigned long a = distinct_element[0], b = distinct_element[1], c = distinct_element[2];

    if( (a + c == 2*b) || (b + c == 2*a) || (b + a == 2*c) )
    {
        set_is_in_AP = true;
    }
    return set_is_in_AP;
}

void get_answer(char answer[], short is_possible)
{
    if(is_possible == true)
    {
        strcpy(answer, "YES");
    }
    else
    {
        strcpy(answer, "NO");
    }
}
