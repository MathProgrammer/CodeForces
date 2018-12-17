#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> prefix_sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        prefix_sum[i] = prefix_sum[i - 1] + A[i];

    vector <int> suffix_sum(no_of_elements + 2, 0);
    for(int i = no_of_elements; i>= 1; i--)
        suffix_sum[i] = suffix_sum[i + 1] + A[i];

    int all_zeroes = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] != 0)
            all_zeroes = false;
    }

    if(all_zeroes)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");

        if(no_of_elements == 1 || prefix_sum[no_of_elements] != 0)
        {
            printf("1\n1 %d\n", no_of_elements);
        }
        else
        {
            int division_point;
            for(int i = 1; i < no_of_elements; i++)
            {
                if(prefix_sum[i] != 0 && suffix_sum[i + 1] != 0)
                {
                    division_point = i;
                    break;
                }
            }

            printf("2\n");
            printf("1 %d\n", division_point);
            printf("%d %d\n", division_point + 1, no_of_elements);
        }
    }
    return 0;
}
