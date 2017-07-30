#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int no_of_balls;
    scanf("%d", &no_of_balls);

    set <int> ball;
    for(int i = 1; i <= no_of_balls; i++)
    {
        int ball_i;
        scanf("%d", &ball_i);
        ball.insert(ball_i);
    }

    bool gift_givable = false;
    for(set <int> :: iterator i = ball.begin(); i != ball.end(); i++)
    {
        int ball_i = *i;

        if(ball.count(ball_i + 1) == 1 && ball.count(ball_i - 1) == 1)
        {
            gift_givable = true;
            break;
        }
    }

    printf(gift_givable ? "YES\n" : "NO\n");
    return 0;
}
