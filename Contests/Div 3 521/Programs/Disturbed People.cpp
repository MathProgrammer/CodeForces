#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_houses;
    cin >> no_of_houses;

    vector <int> light_on(no_of_houses + 1);
    for(int i = 1; i <= no_of_houses; i++)
        cin >> light_on[i];

    int excess_houses = 0;
    for(int i = 2; i < no_of_houses; i++)
    {
        if(light_on[i - 1] && !light_on[i] && light_on[i + 1])
        {
            light_on[i + 1] = false;
            excess_houses++;
        }
    }

    cout << excess_houses << "\n";
    return 0;
}
