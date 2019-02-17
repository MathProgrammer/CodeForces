#include <iostream>

using namespace std;

int main()
{
    int no_of_cities, capacity;
    cin >> no_of_cities >> capacity;

    int fuel;
    if(capacity >= no_of_cities - 1)
    {
        fuel = no_of_cities - 1;
    }
    else
    {
        fuel = capacity - 1;

        for(int i = 1; i <= no_of_cities - capacity; i++)
            fuel += i;
    }

    cout << fuel;
    return 0;
}
