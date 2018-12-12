#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_sequences;
    scanf("%d", &no_of_sequences);

    map <long long, pair<int, int> > used;

    for(int i = 1; i <= no_of_sequences; i++)
    {
        int length_i;
        scanf("%d", &length_i);

        vector <int> A(length_i + 1);

        for(int j = 1; j <= length_i; j++)
            scanf("%d", &A[j]);

        long long sum = 0;
        for(int j = 1; j <= length_i; j++)
            sum += A[j];

        for(int j = 1; j <= length_i; j++)
        {
            long long remaining_sum = sum - A[j];

            if(used.find(remaining_sum) != used.end() && used[remaining_sum].first != i)
            {
                printf("YES\n");
                printf("%d %d\n", used[remaining_sum].first, used[remaining_sum].second);
                printf("%d %d\n", i, j);
                return 0;
            }
            else
            {
                used[remaining_sum] = make_pair(i, j);
            }
        }
    }

    printf("NO\n");

    return 0;
}
