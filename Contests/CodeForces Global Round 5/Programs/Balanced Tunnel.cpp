#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct cars
{
    int entry, exit;

    cars(){};

    const int operator<(cars &C)
    {
        return (entry < C.entry);
    }
};

int main()
{
    int no_of_cars;
    cin >> no_of_cars;

    vector <cars> car_no(no_of_cars);
    for(int i = 0; i < no_of_cars; i++)
    {
        int car;
        cin >> car;

        car_no[car - 1].entry = i;
    }

    int cars_fined = 0;
    for(int i = 0; i < no_of_cars; i++)
    {
        int car;
        cin >> car;

        car_no[car - 1].exit = i;
    }

    sort(all(car_no));

    int maximum_exit_so_far = car_no[0].exit;
    for(int i = 1; i < no_of_cars; i++)
    {
        if(car_no[i].exit < maximum_exit_so_far)
        {
            cars_fined++;
        }

        maximum_exit_so_far = max(maximum_exit_so_far, car_no[i].exit);
    }

    cout << cars_fined << "\n";

    return 0;
}

