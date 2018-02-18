#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    const int MAX = 1e6 + 1;
    vector <int> frequency(MAX, 0);

    int left = 1, right = 1, best_left, best_right, distinct_elements = 0, maximum_length = 0;
    while(right <= no_of_elements)
    {
        frequency[element[right]]++;
        distinct_elements += (frequency[element[right]] == 1);

        while(distinct_elements > k)
        {
            frequency[element[left]]--;
            distinct_elements -= (frequency[element[left]] == 0);
            left++;
        }

        int current_segment_length = right - (left - 1);
        if(current_segment_length > maximum_length)
        {
            maximum_length = current_segment_length;
            best_left = left;
            best_right = right;
        }

        right++;

    }

    printf("%d %d\n", best_left, best_right);
    return 0;
}
