#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int num_1, num_2;
    scanf("%d %d", &num_1, &num_2);

    int one_wins = 0, draw = 0, two_wins = 0;
    for(int dice_i = 1; dice_i <= 6; dice_i++)
    {
        one_wins += (abs(num_1 - dice_i) < abs(num_2 - dice_i));
        two_wins += (abs(num_1 - dice_i) > abs(num_2 - dice_i));
        draw     += (abs(num_1 - dice_i) == abs(num_2 - dice_i));
    }

    printf("%d %d %d", one_wins, draw, two_wins);
    return 0;
}
