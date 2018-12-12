#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int number_of_points;
    scanf("%d", &number_of_points);

    vector <long long> P(number_of_points);
    for(int i = 0; i < number_of_points; i++)
        scanf("%I64d", &P[i]);

    sort(all(P));

    int answer_i = -1, answer_j = -1;

    for(int i = 0; i < number_of_points; i++)
    {
        for(long long power = 1; power <= 1e12; power *= 2)
        {
            int j = upper_bound(all(P), P[i] + power - 1) - P.begin();

            if(P[j] - P[i] == power)
            {
                int k = upper_bound(all(P), P[j] + power - 1) - P.begin();

                if(P[k] - P[j] == power)//Answer can't be more than 3
                {
                    printf("3\n");
                    printf("%I64d %I64d %I64d\n", P[i], P[j], P[k]);
                    return 0;
                }
                else
                {
                    answer_i = i, answer_j = j;
                }
            }
        }
    }

    if(answer_i != -1 && answer_j != -1)
    {
        printf("2\n");
        printf("%I64d %I64d\n", P[answer_i], P[answer_j]);
    }
    else
    {
        printf("1\n");
        printf("%I64d\n", P[0]);
    }

    return 0;
}
