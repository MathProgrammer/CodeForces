#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++) scanf("%d", &A[i]);

    const int oo = 1e7;
    int add[3] = {-1, 0, 1}, min_operations = oo;

    for(int i = 0; i < 3; i++)
    {
        int term_1 = A[0] + add[i];

        for(int j = 0; j < 3; j++)
        {
            int term_2 = A[1] + add[j];

            int difference = term_2 - term_1;

            int no_of_operations = (term_1 != A[0]) + (term_2 != A[1]);

            for(int k = 2; k < no_of_elements; k++)
            {
                if(abs(term_1 + k*difference - A[k]) == 1)
                {
                    no_of_operations++;
                }
                else if(abs(term_1 + k*difference - A[k]) > 1)
                {
                    no_of_operations = oo;
                }
            }

            min_operations = min(min_operations, no_of_operations);
        }
    }

    printf("%d\n", min_operations >= oo ? -1 : min_operations);
    return 0;
}
