#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int MAX_N = 1e5 + 1;
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <int> A(no_of_elements + 1);
    vector <int> frequency(MAX_N + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);

        if(A[i] < MAX_N)
            frequency[A[i]]++;
    }

    vector <int> left(no_of_queries + 1);
    vector <int> right(no_of_queries + 1);
    for(int i = 1; i <= no_of_queries; i++)
        scanf("%d %d", &left[i], &right[i]);

    vector <int> answer(no_of_queries + 1, 0);

    for(int i = 1; i <= MAX_N; i++)
    {
        if(frequency[i] >= i) //There can't be more than 2 root(n) such elements
        {
            vector <int> frequency_till(no_of_elements + 1, 0);

            for(int j = 1; j <= no_of_elements; j++) frequency_till[j] = frequency_till[j - 1] + (A[j] == i);

            for(int q = 1; q <= no_of_queries; q++) answer[q] += (frequency_till[right[q]] - frequency_till[left[q] - 1] == i);
        }
    }

    for(int i = 1; i <= no_of_queries; i++)
        printf("%d\n", answer[i]);
        
    return 0;
}
