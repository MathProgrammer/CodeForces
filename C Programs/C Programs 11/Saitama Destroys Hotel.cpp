#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int  no_of_stops, top_floor;
    scanf("%d %d", &no_of_stops, &top_floor);

    vector <int> floor_stop(no_of_stops);
    vector <int> passenger_arrival_time(no_of_stops);
    for(int i = 0; i < no_of_stops; i++)
        scanf("%d %d", &floor_stop[i], &passenger_arrival_time[i]);

    reverse(all(floor_stop));
    reverse(all(passenger_arrival_time));

    int total_travel_time = 0, current_floor = top_floor;
    for(int i = 0; i < no_of_stops; i++)
    {
        total_travel_time += (current_floor - floor_stop[i]);

        int wait_time = max(passenger_arrival_time[i] - total_travel_time, 0);

        total_travel_time += wait_time;

        current_floor = floor_stop[i];
    }
    total_travel_time += current_floor; //Go to floor 0 from the last floor stop

    printf("%d\n", total_travel_time);
    return 0;
}
