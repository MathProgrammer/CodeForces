#include <stdio.h>
#include <string.h>

#define NO_OF_ROWS 8

void determine_stronger_colour(short, short, char[]);
void read_chessboard(char [][NO_OF_ROWS  + 1]);
void find_strength_of_colour(short *, short *, char[][NO_OF_ROWS + 1]);
short find_the_weight(char);
int main()
{
    char answer[6];//5 + 1. 5 is the maximum size of answer - White
    short white_strength, black_strength;
    char chessboard[NO_OF_ROWS][NO_OF_ROWS + 1]; //It is an array of strings. Each row of board is one string. So, we add 1.

    read_chessboard(chessboard);
    find_strength_of_colour(&white_strength, &black_strength, chessboard);//Pass by reference
    determine_stronger_colour(white_strength, black_strength, answer);

    printf("%s\n",answer);
    return 0;
}

void read_chessboard(char chessboard[][NO_OF_ROWS  + 1])
{
    short i;

    //Chessboard is stored as 8 strings
    for(i = 0; i < NO_OF_ROWS; i++)
    {
        scanf("%s",chessboard[i]);
    }
}

void find_strength_of_colour(short *white_strength, short *black_strength, char chessboard[][NO_OF_ROWS + 1])
{
    short i, j;
    *(white_strength) = 0, *(black_strength) = 0;

    for(i = 0; i < NO_OF_ROWS; i++)
    {
        for(j = 0; j < NO_OF_ROWS; j++)
        {
            if(chessboard[i][j] == '.')
            {
                continue;
            }
            else if( ('A' <= chessboard[i][j]) && (chessboard[i][j] <= 'Z') )
            {
                *(white_strength) = *(white_strength) + find_the_weight(chessboard[i][j]);
            }
            else
            {
                *(black_strength) = *(black_strength) + find_the_weight(chessboard[i][j]);
            }
        }
    }
}

short find_the_weight(char chess_piece)
{
    short weight = 0;
    switch(chess_piece)
    {
        case 'p':
        case 'P': weight = 1;
                break;

        case 'N':
        case 'n':
        case 'B':
        case 'b': weight = 3;
                  break;

        case 'R':
        case 'r': weight = 5;
                break;
        case 'Q':
        case 'q': weight = 9;
                  break;
        default : weight = 0;
    }
    return weight;
}

void determine_stronger_colour(short white_strength, short black_strength, char answer[])
{
    //0 represents white and 1 represents black
    if(white_strength > black_strength)
    {
        strcpy(answer, "White");
    }
    else if(white_strength < black_strength)
    {
        strcpy(answer,"Black");
    }
    else
    {
        strcpy(answer, "Draw");
    }
}
