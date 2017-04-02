#include <stdio.h>

short count_no_of_legal_king_moves(char[]);
int main()
{
    char king_position[3];
    short no_of_legal_moves;

    scanf("%s", king_position);
    no_of_legal_moves = count_no_of_legal_king_moves(king_position);

    printf("%hu\n",no_of_legal_moves);
    return 0;
}

short count_no_of_legal_king_moves(char king_position[])
{
    if( ( (king_position[0] == 'a') || (king_position[0] == 'h') )  && (  (king_position[1] == '1') || (king_position[1] == '8') ) )//Corner piece
    {
        return 3;
    }
    else if( ( (king_position[0] == 'a') || (king_position[0] == 'h') )  || (  (king_position[1] == '1') || (king_position[1] == '8') ) )//Border row or column but not corner piece
    {
            return 5;
    }
    else
    {
        return 8;
    }
}
