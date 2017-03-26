#include <stdio.h>
#include <stdlib.h>

#define PRIMARY_FILLER_LENGTH 4
#define ADDITIONAL_FILLER_LENGTH 3

#define true 1
#define false 0

void remove_filler_from_interview(char *, char *);
short find_filler_length_from_here(char *, short);
short search_for_additional_filler(char *, short);
int main()
{
    short size_of_string;

    scanf("%hu",&size_of_string);

    char *interview = malloc( (size_of_string + 1)*sizeof(char) );
    char *interview_without_filler = malloc( (size_of_string + 1)*sizeof(char) );

    scanf("%s",interview);

    remove_filler_from_interview(interview, interview_without_filler);

    printf("%s",interview_without_filler);

    free(interview);
    free(interview_without_filler);
    return 0;
}

void remove_filler_from_interview(char *interview, char *interview_without_filler)
{
    short i = 0, length_of_filler_from_i, final_interview_index = 0, count;

    while( *(interview + i) != '\0')
    {
        length_of_filler_from_i = find_filler_length_from_here(interview, i);

        //If there is no filler here, then just put in the same character as the normal interview and proceed to the next character
        if(length_of_filler_from_i == 0)
        {
            *(interview_without_filler + final_interview_index) = *(interview + i);
            final_interview_index++;
            i++;
        }
        else
        {
            for(count = 0; count < 3; count++, final_interview_index++)//Filling three asterisks
            {
                *(interview_without_filler + final_interview_index) = '*';
            }
            i = i + length_of_filler_from_i; //Start checking the interview from where the current filler ended
        }
    }
    *(interview_without_filler + final_interview_index) = '\0';//Terminating the string
}

short find_filler_length_from_here(char *interview, short i)
{
    short filler_length = 0, primary_filler_index = 0, primary_filler_found = true, additional_filler_found = false;
    char primary_filler[PRIMARY_FILLER_LENGTH] = "ogo";

    for(primary_filler_index = 0; primary_filler[primary_filler_index] !=  '\0'; primary_filler_index++)
    {
        if(*(primary_filler + primary_filler_index) != *(interview + i + primary_filler_index) )
        {
            primary_filler_found = false;
            break;
        }
    }

    if(primary_filler_found == false)//If not found, then return filler length is 0
    {
        filler_length = 0;
    }
    else //If a primary filler is found, then search for the secondary filler and update the filler length accordingly
    {
        filler_length = filler_length + 3;
        additional_filler_found = search_for_additional_filler(interview, i+filler_length);

        while(additional_filler_found)
        {
            filler_length = filler_length + 2;
            additional_filler_found = search_for_additional_filler(interview, i+filler_length);
        }

    }

    return filler_length;
}

short search_for_additional_filler(char *interview, short here)
{
    short additional_filler_found = true, additional_filler_index;
    char additional_filler[ADDITIONAL_FILLER_LENGTH] = "go";

    for(additional_filler_index = 0; additional_filler[additional_filler_index] != '\0'; additional_filler_index++)
    {
        if(*(interview + here + additional_filler_index) != additional_filler[additional_filler_index])
        {
            additional_filler_found = false;
            break;
        }
    }
    return additional_filler_found;
}
