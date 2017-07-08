#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector <int> is_used(3000 + 2, false);
    int no_of_tests, test_i, default_for_next;
    scanf("%d", &no_of_tests);

    for(int i = 1; i <= no_of_tests; i++)
    {
        scanf("%d", &test_i);
        is_used[test_i] = true;
    }

    for(int i = 1; i <= 3001; i++)
    {
        if(is_used[i] == false)
        {
            default_for_next = i;
            break;
        }
    }

    printf("%d\n", default_for_next);
    return 0;
}
