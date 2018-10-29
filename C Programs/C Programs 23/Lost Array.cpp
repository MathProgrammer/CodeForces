#include <cstdio>
#include <vector>

using namespace std;

int is_possible(vector <int> &A, int k)
{
    for(int i = 1; i < A.size(); i++)
    {
        if(A[i] != A[(i%k)])
            return false;
    }

    return true;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> X(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        X[i] = A[i + 1] - A[i];

    vector <int> answer;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(is_possible(X, i))
        {
            answer.push_back(i);
        }
    }

    printf("%d\n", answer.size() == 0 ? -1 : answer.size());
    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);
    return 0;
}
