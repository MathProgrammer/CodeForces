#include <cstdio>
#include <map>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    const int oo = 1e9 + 1;
    int no_of_people, min_strength = oo, max_strength = 0;
    scanf("%d", &no_of_people);

    map <int, int> strength_frequency;
    for(int i = 1; i <= no_of_people; i++)
    {
        int strength_i;
        scanf("%d", &strength_i);

        strength_frequency[strength_i]++;
        min_strength = min(strength_i, min_strength);
        max_strength = max(strength_i, max_strength);
    }

    int number_of_people_supported = max(0, no_of_people - strength_frequency[max_strength] - strength_frequency[min_strength]);
    printf("%d\n", number_of_people_supported);
    return 0;
}
