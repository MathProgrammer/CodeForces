#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    const int no_of_friends = 3;
    vector <int> location(no_of_friends);
    scanf("%d %d %d", &location[0], &location[1], &location[2]);

    sort(all(location));

    int minimum_distance = 300;
    for(int meet_point = location[0]; meet_point <= location[2]; meet_point++)
    {
        int distance = abs(meet_point - location[0]) + abs(meet_point - location[1]) + abs(meet_point - location[2]);

        minimum_distance = min(minimum_distance, distance);
    }

    printf("%d\n", minimum_distance);
    return 0;
}
