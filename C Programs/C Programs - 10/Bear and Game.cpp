#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_interesting_minutes, interesting_minute_i, tv_on_minutes = 0;
    scanf("%d", &no_of_interesting_minutes);

    bool tv_on = true;

    vector <int> interesting_minute;
    interesting_minute.push_back(0);
    for(int i = 1; i <= no_of_interesting_minutes; i++)
    {
        scanf("%d", &interesting_minute_i);
        interesting_minute.push_back(interesting_minute_i);
    }

    if(interesting_minute.back() != 90)
        interesting_minute.push_back(90);

    for(unsigned int i = 1; i < interesting_minute.size() ; i++)
    {
        if(tv_on)
        {
            int boring_interval = (interesting_minute[i] - 1) - interesting_minute[i - 1];

            if(boring_interval >= 15)
            {
                tv_on_minutes += 15;
                tv_on = false;
            }
            else
            {
                tv_on_minutes += boring_interval + 1; //Watch the boring interval + the interesting minute
            }
        }
    }

    printf("%d\n", tv_on_minutes);
    return 0;
}
