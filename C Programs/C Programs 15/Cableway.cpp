#include <cstdio>

int main()
{
    int red, blue, green;
    scanf("%d %d %d", &red, &green, &blue);

    int red_rides = red/2 + red%2;
    int blue_rides = blue/2 + blue%2;
    int green_rides = green/2 + green%2;

    const int ONE_RIDE_DURATION = 30;
    int no_of_minutes, last_ride_arrival;

    if(red_rides > blue_rides && red_rides > green_rides)
    {
        last_ride_arrival = 3*(red_rides - 1);
        no_of_minutes = last_ride_arrival + ONE_RIDE_DURATION;
    }
    else if(green_rides >= red_rides && green_rides > blue_rides)
    {
        last_ride_arrival = 3*(green_rides - 1) + 1;
        no_of_minutes = last_ride_arrival + ONE_RIDE_DURATION;
    }
    else if(blue_rides >= red_rides && blue_rides >= green_rides)
    {
        last_ride_arrival = 3*(blue_rides - 1) + 2;
        no_of_minutes = last_ride_arrival + ONE_RIDE_DURATION;
    }

    printf("%d\n", no_of_minutes);
    return 0;
}
