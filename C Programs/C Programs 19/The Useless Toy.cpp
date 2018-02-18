#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map <char, int> positions;

    positions['v'] = 0;
    positions['<'] = 1;
    positions['^'] = 2;
    positions['>'] = 3;

    char start_position, end_position;
    int no_of_spins;

    scanf("%c %c %d", &start_position, &end_position, &no_of_spins);
    int first_position = positions[start_position];
    int final_position = positions[end_position];

    if( (first_position + no_of_spins%4)%4 == final_position && (first_position + (4 - no_of_spins%4))%4 == final_position)
        printf("undefined\n");
    else if( (first_position + no_of_spins%4)%4 == final_position)
        printf("cw\n");
    else if( (first_position + (4 - no_of_spins%4))%4 == final_position)
        printf("ccw\n");
    else
        printf("undefined\n");

    return 0;
}
