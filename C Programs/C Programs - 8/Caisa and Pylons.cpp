#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int number_of_plyons;
    scanf("%d", &number_of_plyons);

    vector <int> height (number_of_plyons + 1);
    for(int i = 1; i <= number_of_plyons; i++)
        scanf("%d", &height[i]);

    int money_needed = height[1];
    int energy = 0;
    for(int i = 1; i <= number_of_plyons - 1; i++)
    {
        energy += (height[i] - height[i + 1]);

        if(energy < 0)
        {
            money_needed += abs(energy);
            energy = 0;
        }
    }

    printf("%d\n", money_needed);
    return 0;
}
