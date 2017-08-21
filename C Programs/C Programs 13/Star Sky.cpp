#include <cstdio>

#define MAX_BRIGHTNESS 10
#define MAX_LENGTH 100

int main()
{
    int no_of_stars, no_of_views, maximum_brightness;
    scanf("%d %d %d", &no_of_stars, &no_of_views, &maximum_brightness);

    int no_of_stars_of_initial_brightness_in[MAX_BRIGHTNESS + 1][MAX_LENGTH + 1][MAX_LENGTH + 1] = {{{0}}};

    for(int star_i = 1; star_i <= no_of_stars; star_i++)
    {
        int brightness_i, x_i, y_i;
        scanf("%d %d %d", &x_i, &y_i, &brightness_i);

        no_of_stars_of_initial_brightness_in[brightness_i][x_i][y_i]++;
    }

    for(int brightness_i = 0; brightness_i <= maximum_brightness; brightness_i++)
    {
        for(int x_i = 1; x_i <= MAX_LENGTH; x_i++)
        {
            for(int y_i = 1; y_i <= MAX_LENGTH; y_i++)
            {
                no_of_stars_of_initial_brightness_in[brightness_i][x_i][y_i] += no_of_stars_of_initial_brightness_in[brightness_i][x_i][y_i - 1]
                                                                              + no_of_stars_of_initial_brightness_in[brightness_i][x_i - 1][y_i]
                                                                              - no_of_stars_of_initial_brightness_in[brightness_i][x_i - 1][y_i - 1];
            }
        }
    }

    while(no_of_views--)
    {
        int time, x_1,y_1, x_2, y_2;
        scanf("%d %d %d %d %d", &time, &x_1, &y_1, &x_2, &y_2);

        int sum_of_brightness = 0;

        for(int brightness_i = 0; brightness_i <= maximum_brightness; brightness_i++)
        {
            int no_of_stars_of_this_brightness = no_of_stars_of_initial_brightness_in[brightness_i][x_2][y_2]
                                               - no_of_stars_of_initial_brightness_in[brightness_i][x_2][y_1 - 1]
                                               - no_of_stars_of_initial_brightness_in[brightness_i][x_1 - 1][y_2]
                                               + no_of_stars_of_initial_brightness_in[brightness_i][x_1 - 1][y_1 - 1];

            int final_brightness = (brightness_i + time)%(maximum_brightness + 1);


            sum_of_brightness += no_of_stars_of_this_brightness*final_brightness;
        }

        printf("%d\n", sum_of_brightness);
    }
    return 0;
}
