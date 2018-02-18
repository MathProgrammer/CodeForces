#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int number_of_cities, number_of_towers;
    scanf("%d %d", &number_of_cities, &number_of_towers);

    vector <int> city(number_of_cities);
    for(int i = 0; i < number_of_cities; i++)
        scanf("%d", &city[i]);

    vector <int> tower(number_of_towers);
    for(int i = 0; i <  number_of_towers; i++)
        scanf("%d", &tower[i]);

    int min_range = 0;

    for(int i = 0; i < number_of_cities; i++)
    {
        int position = lower_bound(all(tower), city[i]) - tower.begin();

        int closest_tower = 2e9;

        if(position != number_of_towers) closest_tower = min(closest_tower, abs(tower[position] - city[i]));

        if(position != 0) closest_tower = min(closest_tower, abs(tower[position - 1] - city[i]));

        min_range = max(min_range, closest_tower);
    }

    printf("%d\n", min_range);
    return 0;
}
