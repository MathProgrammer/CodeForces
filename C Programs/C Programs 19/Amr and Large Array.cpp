#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int LIMIT = 1e6;
    vector <int> A(no_of_elements + 1, 0);
    vector <int> frequency(LIMIT + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);
        frequency[A[i]]++;
    }

    int max_frequency = 0;
    for(int i = 1; i <= LIMIT; i++)
        max_frequency = max(max_frequency, frequency[i]);

    vector <int> rightmost_occurence(LIMIT + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        rightmost_occurence[A[i]] = i;

    vector <int> leftmost_occurence(LIMIT + 1, 0);
    for(int i = no_of_elements; i >= 1; i--)
        leftmost_occurence[A[i]] = i;

    int minimum_segment_length = no_of_elements + 1;
    int answer;
    for(int i = 1; i <= LIMIT; i++)
    {
        if(frequency[i] == max_frequency)
        {
            int subsegment_length = rightmost_occurence[i] - (leftmost_occurence[i] - 1);

            if(subsegment_length < minimum_segment_length)
            {
                answer = i;
                minimum_segment_length = subsegment_length;
            }
        }
    }

    printf("%d %d\n", leftmost_occurence[answer], rightmost_occurence[answer]);
    return 0;
}
