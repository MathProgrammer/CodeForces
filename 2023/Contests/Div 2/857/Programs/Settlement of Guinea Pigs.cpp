#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_days;
    cin >> no_of_days;

    vector <int> event(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
    {
        cin >> event[i];
    }

    const int ADOPT = 1, DOCTOR = 2;
    int bought_avaries = 0, half_avaries = 0, free_avaries = 0;
    for(int i = 1; i <= no_of_days; i++)
    {
        switch(event[i])
        {
            case ADOPT :
            {
                if(free_avaries > 0)
                {
                    free_avaries--;
                }
                else
                {
                    bought_avaries++;
                }

                half_avaries++;

                break;
            }

            case DOCTOR :
            {
                int pairs = 0;
                if(half_avaries%2 == 0)
                {
                    pairs = (half_avaries - 2)/2;

                }
                else
                {
                    pairs = (half_avaries - 1)/2;
                }

                free_avaries += pairs;
                half_avaries -= 2*pairs;
                break;
            }
        }
    }

    cout << bought_avaries << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

