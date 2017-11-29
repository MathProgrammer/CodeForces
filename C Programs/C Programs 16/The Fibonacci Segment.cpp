#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <int> longest_segment_ending(no_of_elements + 1, 1);
    int longest_segment = 1;
    for(int i = 2; i <= no_of_elements; i++)
    {
        if(i == 2)
            longest_segment_ending[i] = 2;
        else
            longest_segment_ending[i] = (element[i] == element[i - 1] + element[i - 2] ? longest_segment_ending[i - 1] + 1 : 2);

        longest_segment = max(longest_segment, longest_segment_ending[i]);
    }

    printf("%d\n", longest_segment);
    return 0;
}
