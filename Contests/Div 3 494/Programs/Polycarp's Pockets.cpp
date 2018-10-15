#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX_N = 115;
    vector <int> frequency(MAX_N, 0);
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);
        frequency[element]++;
    }

    int max_frequency = 0;
    for(int i = 0; i < MAX_N; i++)
        max_frequency = max(max_frequency, frequency[i]);

    printf("%d\n", max_frequency);

    return 0;
}

