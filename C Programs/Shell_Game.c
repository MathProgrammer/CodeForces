#include <stdio.h>

short find_initial_position(short, short);
int main()
{
    unsigned long no_of_turns;
    short effective_no_of_turns, current_ball_position, initial_ball_position;

    scanf("%lu %hu",&no_of_turns, &current_ball_position);

    effective_no_of_turns = no_of_turns%6; //The same permutation repeats after every six permutations

    initial_ball_position = find_initial_position(current_ball_position, effective_no_of_turns);
    printf("%hu\n",initial_ball_position);
    return 0;
}

short find_initial_position(short current_ball_position, short turn_no)
{
    if(turn_no == 0)//First permutation. It is the base case
    {
        return current_ball_position;
    }
    else
    {
        if(turn_no%2 == 0) //Even turn - middle and right interchanged. Left stays invariant
        {
            switch(current_ball_position)
            {
                case 0: return find_initial_position(current_ball_position, turn_no - 1);
                        break;
                case 1: return find_initial_position(current_ball_position+1, turn_no - 1);
                        break;
                case 2: return find_initial_position(current_ball_position-1, turn_no - 1);
                        break;
            }
        }
        else //It was an odd turn - middle and left interchange. Right stays invariant
        {
            switch(current_ball_position)
            {
                case 0: return find_initial_position(current_ball_position + 1, turn_no - 1);
                        break;
                case 1: return find_initial_position(current_ball_position - 1, turn_no - 1);
                        break;
                case 2: return find_initial_position(current_ball_position, turn_no - 1);
                        break;
            }
        }
    }
}
