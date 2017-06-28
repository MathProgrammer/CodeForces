#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int number_of_elements, element_i;
    scanf("%d", &number_of_elements);

    map <int, int> frequency;
    for(int i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &element_i);
        frequency[element_i]++;
    }

    int max_frequency = 0;
    for(map <int, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
        max_frequency = max(max_frequency, it->second);

    int half_size = number_of_elements/2 + number_of_elements%2;

    printf(max_frequency > half_size ? "NO\n" : "YES\n");
    return 0;
}
