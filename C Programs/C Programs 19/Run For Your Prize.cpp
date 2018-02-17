#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> items(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &items[i]);

    const int A_POSITION = 1;
    vector <int> time_A(no_of_elements + 2, 0);
    for(int i = 1; i <= no_of_elements; i++) time_A[i] = (items[i] - A_POSITION);

    const int B_POSITION = 1e6;
    vector <int> time_B(no_of_elements + 2, 0);
    for(int i = 1; i <= no_of_elements; i++) time_B[i] = (B_POSITION - items[i]);

    int minimum_time = B_POSITION + A_POSITION;

    for(int i = 0; i <= no_of_elements; i++)
    {
        int time_if_A_picks_first_i = max(time_A[i], time_B[i + 1]);
        minimum_time = min(minimum_time, time_if_A_picks_first_i);
    }

    printf("%d\n", minimum_time);
    return 0;
}
