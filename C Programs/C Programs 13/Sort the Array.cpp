#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int number_of_elements;
    scanf("%d", &number_of_elements);

    vector <int> element(number_of_elements + 1);
    for(int i = 1; i <= number_of_elements; i++)
        scanf("%d", &element[i]);

    int descending_segments = 0, in_descending_segment = false, reversed_segment_fits = false;
    int segment_start = 1, segment_end = number_of_elements;

    for(int i = 2; i <= number_of_elements && descending_segments <= 1; i++)
    {
        if(in_descending_segment)
        {
            if(element[i] > element[i - 1])
            {
                segment_end = i - 1;
                in_descending_segment = false;
            }
        }
        else
        {
            if(element[i] < element[i - 1])
            {
                in_descending_segment = true;
                segment_start = i - 1;

                descending_segments++;
            }
        }
    }

    if(descending_segments == 0)
        segment_end = segment_start;

    if( (segment_end == number_of_elements || element[segment_start] <= element[segment_end + 1] ) &&
        (segment_start == 1 || element[segment_end] >= element[segment_start - 1]) )
    {
        reversed_segment_fits = true;
    }

    if(descending_segments <= 1 && reversed_segment_fits)
        printf("yes\n%d %d\n", segment_start, segment_end);
    else
        printf("no\n");

    return 0;
}
