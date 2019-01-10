#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX = 3;
    vector <int> frequency(MAX, 0);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%1d", &A[i]);
        frequency[A[i]]++;
    }

    for(int i = 1; i <= no_of_elements && frequency[0] < no_of_elements/3; i++)
    {
        if(A[i] != 0 && frequency[A[i]] > no_of_elements/3)
        {
            frequency[A[i]]--;
            frequency[0]++;

            A[i] = 0;
        }
    }

    for(int i = no_of_elements; i >= 1 && frequency[2] < no_of_elements/3; i--)
    {
        if(A[i] != 2 && frequency[A[i]] > no_of_elements/3)
        {
            frequency[A[i]]--;
            frequency[2]++;

            A[i] = 2;
        }
    }

    for(int i = 1; i <= no_of_elements && frequency[1] < no_of_elements/3 && frequency[2] > no_of_elements/3; i++)
    {
        if(A[i] == 2)
        {
            frequency[2]--;
            frequency[1]++;

            A[i] = 1;
        }
    }

    for(int i = no_of_elements; i >= 1 && frequency[1] < no_of_elements/3 && frequency[0] > no_of_elements/3; i--)
    {
        if(A[i] == 0)
        {
            frequency[0]--;
            frequency[1]++;

            A[i] = 1;
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        printf("%d", A[i]);
    }

    return 0;
}
