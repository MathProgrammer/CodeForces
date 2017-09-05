#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    const int limit = 5000;
    vector <int> is_present(limit + 1, false);
    for(int i = 1; i <= n; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        is_present[element_i] = true;
    }

    int no_of_changes = 0;
    for(int i = 1; i <= n; i++)
        no_of_changes += (!is_present[i]);

    printf("%d\n", no_of_changes);
    return 0;
}
