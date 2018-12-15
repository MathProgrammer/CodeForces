#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> B(no_of_elements/2 + 1);
    for(int i = 1; i <= no_of_elements/2; i++)
        scanf("%I64d", &B[i]);

    vector <long long> A(no_of_elements + 2, 0);
    int front = 0, back = no_of_elements + 1;

    const long long oo = 2e18;
    A[back] = oo;

    for(int i = 1; i <= no_of_elements/2; i++)
    {
        if(B[i] - A[front] > A[back])
        {
            A[back - 1] = A[back]; back--;
            A[front + 1] = B[i] - A[back]; front++;
        }
        else
        {
            A[front + 1] = A[front]; front++;
            A[back - 1] = B[i] - A[front]; back--;
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
        printf("%I64d ", A[i]);

    return 0;
}
