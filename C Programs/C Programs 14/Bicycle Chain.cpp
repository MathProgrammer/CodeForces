#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_pedal_stars;
    scanf("%d", &no_of_pedal_stars);

    vector <int> pedal_star(no_of_pedal_stars);
    for(int i = 0; i < no_of_pedal_stars; i++)
        scanf("%d", &pedal_star[i]);

    int no_of_wheel_stars;
    scanf("%d",&no_of_wheel_stars);

    vector <int> wheel_star(no_of_wheel_stars);
    for(int i = 0; i < no_of_wheel_stars; i++)
        scanf("%d", &wheel_star[i]);

    int maximum_ratio = 0, no_of_maxima = 0;
    for(int i = 0; i < no_of_pedal_stars; i++)
    {
        for(int j = 0; j < no_of_wheel_stars; j++)
        {
            if(wheel_star[j]%pedal_star[i] == 0)
            {
                int this_ratio = wheel_star[j]/pedal_star[i];

                if(this_ratio == maximum_ratio)
                {
                    no_of_maxima++;
                }
                else if(this_ratio > maximum_ratio)
                {
                    maximum_ratio = this_ratio, no_of_maxima = 1;
                }
            }
        }
    }

    printf("%d\n", no_of_maxima);
    return 0;
}
