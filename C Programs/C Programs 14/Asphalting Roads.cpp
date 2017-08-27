#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_roads;
    scanf("%d", &no_of_roads);

    const int MAX_ROADS = 50 + 1;
    vector <int> horizontal_is_asphalted(MAX_ROADS, false);
    vector <int> vertical_is_asphalted(MAX_ROADS, false);

    vector <int> new_asphalt_applied_on_day;

    for(int day_i = 1; day_i <= no_of_roads*no_of_roads; day_i++)
    {
        int road_1, road_2;
        scanf("%d %d", &road_1, &road_2);

        if(!horizontal_is_asphalted[road_1] && !vertical_is_asphalted[road_2])
        {
            horizontal_is_asphalted[road_1] = vertical_is_asphalted[road_2] = true;
            new_asphalt_applied_on_day.push_back(day_i);
        }
    }

    for(unsigned int i = 0; i < new_asphalt_applied_on_day.size(); i++)
        printf("%d ", new_asphalt_applied_on_day[i]);

    return 0;
}
