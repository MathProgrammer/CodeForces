#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1200
void get_final_emotions(char[], short);
int main()
{
    short no_of_layers;
    char emotions[MAX_SIZE];
    scanf("%hu",&no_of_layers);

    get_final_emotions(emotions, no_of_layers);
    printf("%s\n",emotions);
    return 0;
}

void get_final_emotions(char emotions[], short no_of_layers)
{
    short i;
    char odd_emotion[8] = "I hate ", even_emotion[8] = "I love ";
    strcpy(emotions, "");

    for(i = 1; i <= no_of_layers; i++)
    {
        if(i%2 == 1)
        {
            strcat(emotions, odd_emotion);
        }
        else
        {
            strcat(emotions, even_emotion);
        }

        if(i != no_of_layers)
        {
            strcat(emotions, "that ");
        }
        else
        {
            strcat(emotions, "it");
        }
    }
}
