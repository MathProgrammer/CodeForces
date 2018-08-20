#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX = 2e6 + 5;
    vector <int> A(no_of_elements + 1);
    vector <int> is_present(MAX, false);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);

        is_present[A[i]] = true;
    }

    vector <int> nearest(MAX, 0);
    for(int i = 1; i < MAX; i++)
    {
        nearest[i] = (is_present[i - 1] ? i - 1 : nearest[i - 1]);
    }

    int max_mod = 0;
    for(int i = 1; i < MAX; i++)
    {
        if(!is_present[i]) continue;

        for(int j = 2*i; j < MAX; j += i)
        {
            max_mod = max(max_mod, nearest[j]%i);
        }
    }

    printf("%d\n", max_mod);
    return 0;
}
