#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    int last_element, longest_sequence = 0;

    map <int, int> answer_with_last_element;

    for(int i = 1; i <= no_of_elements; i++)
    {
        answer_with_last_element[A[i]] = 1 + answer_with_last_element[A[i] - 1];

        if(answer_with_last_element[A[i]] > longest_sequence)
        {
            longest_sequence = answer_with_last_element[A[i]];
            last_element = A[i];
        }
    }

    vector <int> index;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(index.size() == 0)
        {
            if(A[i] == last_element - longest_sequence + 1)
                index.push_back(i);
        }
        else if(A[i] == A[index.back()] + 1)
        {
            index.push_back(i);
        }
    }

    printf("%d\n", longest_sequence);
    for(int i = 0; i < longest_sequence; i++) printf("%d ", index[i]);

    return 0;
}
