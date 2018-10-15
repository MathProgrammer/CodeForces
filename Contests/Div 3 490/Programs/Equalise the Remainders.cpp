#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> position[MAX_N];

int main()
{
    typedef long long LL;
    int no_of_elements, m;
    scanf("%d %d", &no_of_elements, &m);

    vector <LL> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%I64d", &A[i]);

    int target = no_of_elements/m;
    for(int i = 1; i <= no_of_elements; i++)
    {
        position[A[i]%m].push_back(i);
    }

    long long no_of_changes = 0;
    vector <int> extra;

    for(int runs = 1; runs <= 2; runs++)
    {
        for(int i = 0; i < m; i++)
        {
            while(position[i].size() > target)
            {
                int index = position[i].back();

                extra.push_back(index);

                position[i].pop_back();
            }

            while(position[i].size() < target && extra.size() > 0)
            {
                int index = extra.back();

                no_of_changes += (A[index]%m < i ? i - A[index]%m : m - A[index]%m + i);

                A[index] += (A[index]%m < i ? i - A[index]%m : m - A[index]%m + i);

                position[i].push_back(index);

                extra.pop_back();
            }
        }
    }

    printf("%I64d\n", no_of_changes);
    for(int i = 1; i <= no_of_elements; i++)
        printf("%I64d ", A[i]);

    return 0;
}
