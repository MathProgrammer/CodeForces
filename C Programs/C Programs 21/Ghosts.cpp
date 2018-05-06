#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int no_of_points, a, b;
    scanf("%d %d %d", &no_of_points, &a, &b);

    long long total_collisions = 0;
    map < pair<int, int>, int > slope_count;
    map <long long, int> intersections;

    for(int i = 1; i <= no_of_points; i++)
    {
        int x, vx, vy;
        scanf("%d %d %d", &x, &vx, &vy);

        total_collisions += intersections[a*1LL*vx - vy] - slope_count[make_pair(vx, vy)]; //Parallel points don't meet.

        slope_count[make_pair(vx, vy)]++;
        intersections[a*1LL*vx - vy]++;
    }

    total_collisions *= 2;

    printf("%I64d\n", total_collisions);
    return 0;
}
