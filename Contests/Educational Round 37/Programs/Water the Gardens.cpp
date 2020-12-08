#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int number_of_taps, number_of_beds;
    scanf("%d %d", &number_of_beds, &number_of_taps);

    vector <int> tap(number_of_taps + 1, 0);
    for(int i = 1; i <= number_of_taps; i++)
        scanf("%d", &tap[i]);

    int time = tap[1];

    for(int i = 1; i < number_of_taps; i++)
    {
        int distance = tap[i + 1] - tap[i] + 1;

        int time_for_this_patch = distance/2 + distance%2 ;

        time = max(time, time_for_this_patch);
    }

    time = max(time, number_of_beds - tap.back() + 1);

    printf("%d\n", time);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
