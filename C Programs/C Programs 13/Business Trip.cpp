#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int minimum_growth;
    scanf("%d", &minimum_growth);

    const int no_of_months = 12;
    vector <int> growth(no_of_months);
    for(int i = 0; i < no_of_months; i++)
        scanf("%d", &growth[i]);

    sort(all(growth));
    reverse(all(growth));

    int month_i = 0, plant_growth = 0;
    while(plant_growth < minimum_growth && month_i < no_of_months)
    {
        plant_growth += growth[month_i++];
    }

    printf("%d\n", plant_growth < minimum_growth ? -1 : month_i);
    return 0;
}
