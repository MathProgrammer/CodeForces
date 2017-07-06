#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_stations, start, destination;
    scanf("%d", &no_of_stations);

    vector <int> distance(no_of_stations + 1);
    for(int i = 1; i <= no_of_stations; i++)
        scanf("%d", &distance[i]);

    scanf("%d %d", &start, &destination);

    int straight_distance = 0;
    for(int i = start; i != destination; i = (i == no_of_stations ? 1 : i + 1))
        straight_distance += distance[i];

    int round_distance = 0;
    for(int i = destination; i != start; i = (i == no_of_stations ? 1 : i + 1))
        round_distance += distance[i];

    printf("%d\n", min(straight_distance, round_distance));
    return 0;
}
