#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int list_1_size, list_2_size;
    scanf("%d %d", &list_1_size, &list_2_size);

    vector <int> in_A(10, false);
    for(int i = 1; i <= list_1_size; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        in_A[a_i] = true;
    }

    vector <int> in_B(10, false);
    for(int i = 1; i <= list_2_size; i++)
    {
        int b_i;
        scanf("%d", &b_i);

        in_B[b_i] = true;
    }

    int answer = -1;

    for(int i = 1; i <= 9; i++)
    {
        if(in_A[i] && in_B[i])
        {
            answer = i;
            break;
        }
    }

    if(answer != -1)
    {
        printf("%d\n", answer);
        return 0;
    }

    for(int i = 1; i <= 9 && answer == -1; i++)
    {
        for(int j = i + 1; j <= 9; j++)
        {
            if( (in_A[i] && in_B[j]) || (in_A[j] && in_B[i]) )
            {
                answer = 10*i + j;
                break;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
