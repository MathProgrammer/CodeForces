#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int number_of_elements, number_of_queries;
    scanf("%d %d", &number_of_elements, &number_of_queries);

    vector <int> A(number_of_elements + 1, 0);
    for(int i = 1; i <= number_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> first_unequal_position_left(number_of_elements + 1, 0);
    for(int i = 1; i <= number_of_elements; i++)
        first_unequal_position_left[i] = (A[i] != A[i - 1] ? i - 1 : first_unequal_position_left[i - 1]);

    while(number_of_queries--)
    {
        int left, right, x;
        scanf("%d %d %d", &left, &right, &x);

        int answer;

        if(A[right] != x)
            answer = right;
        else if(A[right] == x)
            answer = (first_unequal_position_left[right] >= left ? first_unequal_position_left[right] : -1);

        printf("%d\n", answer);
    }
    return 0;
}
