#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, x;
    scanf("%d %d", &no_of_elements, &x);

    const int MAX = 101;
    vector <int> frequency(MAX, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency[element_i]++;
    }

    int no_of_missing_elements_before_x = 0;
    int x_present = frequency[x];

    for(int i = 0; i < x; i++)
    {
        no_of_missing_elements_before_x += (frequency[i] == 0);
    }

    printf("%d\n", no_of_missing_elements_before_x + x_present);
    return 0;
}
