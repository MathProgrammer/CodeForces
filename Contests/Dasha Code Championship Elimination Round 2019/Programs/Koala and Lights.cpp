#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int no_of_lights;
    cin >> no_of_lights;

    string initial;
    cin >> initial;

    vector <int> start(no_of_lights);
    vector <int> difference(no_of_lights);
    for(int i = 0; i < no_of_lights; i++)
    {
        cin >> difference[i] >> start[i];
    }

    const int MAX_TIME = 1001, ON = 0, OFF = 1;
    vector <int> lights_on_at(MAX_TIME, 0);

    for(int i = 0; i < no_of_lights; i++)
    {
        int state = (initial[i] == '0' ? OFF : ON);

        if(initial[i] == '1')
        {
            for(int time = 0; time < start[i]; time++)
            {
                lights_on_at[time]++;
            }
        }

        for(int time = start[i]; time < MAX_TIME; time++)
        {
            if((time - start[i])%difference[i] == 0)
            {
                state = (state == ON ? OFF : ON);
            }

            if(state == ON)
            {
                lights_on_at[time]++;
            }
        }
    }

    int max_lights = 0;
    for(int t = 0; t < MAX_TIME; t++)
    {
        max_lights = max(max_lights, lights_on_at[t]);
    }

    cout << max_lights;
    return 0;
}
