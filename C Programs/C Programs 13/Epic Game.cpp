#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int winner;
    for(int turn_i = 0; n > 0; turn_i++)
    {
        int current_player = (turn_i%2 == 0 ? a : b) ;
        n -= gcd(current_player, n);

        if(n == 0)
            winner = turn_i%2;
    }

    printf("%d\n", winner);
    return 0;
}
