#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 2);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <int> longest_increasing_to_left(no_of_elements + 2, 1);
    longest_increasing_to_left[1] = 0;

    for(int i = 3; i <= no_of_elements; i++)
    {
        if(element[i - 1] > element[i - 2])
            longest_increasing_to_left[i] = longest_increasing_to_left[i - 1] + 1;
    }

    vector <int> longest_increasing_to_right(no_of_elements + 2, 1);
    longest_increasing_to_right[no_of_elements] = 0;

    for(int i = no_of_elements - 2; i >= 0; i--)
    {
        if(element[i + 1] < element[i + 2])
            longest_increasing_to_right[i] = longest_increasing_to_right[i + 1] + 1;
    }

    int longest_increasing_subsequence = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int length_by_changing_current_element = max(longest_increasing_to_left[i], longest_increasing_to_right[i]) + 1;

        if(i > 1 && i < no_of_elements)
        {
            if(element[i + 1] - element[i - 1] >= 2)
            {
                length_by_changing_current_element = longest_increasing_to_left[i] + longest_increasing_to_right[i] + 1;
            }
        }

        longest_increasing_subsequence = max(longest_increasing_subsequence, length_by_changing_current_element);
    }

    printf("%d\n", longest_increasing_subsequence);
    return 0;
}
