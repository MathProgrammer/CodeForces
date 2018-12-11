#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map <long long, int> cube_root;
    const int MAX_CUBE_ROOT = 1e6;
    for(long long i = 1; i <= MAX_CUBE_ROOT; i++)
        cube_root[i*i*i] = i;

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        long long a, b;
        scanf("%I64d %I64d", &a, &b);

        int possible = true;
        if(cube_root[a*b] == 0)
        {
            possible = false;
            printf("No\n");
            continue;
        }

        long long winnings_a = (a)/cube_root[a*b];
        long long winnings_b = (b)/cube_root[a*b];

        long long expected_a = (winnings_a*winnings_a*winnings_b);
        long long expected_b = (winnings_b*winnings_b*winnings_a);

        if(a != expected_a || b != expected_b)
            possible = false;

        printf(possible ? "Yes\n" : "No\n");
    }

    return 0;
}
