#include <cstdio>
#include <vector>

#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    int no_of_displays;
    scanf("%d", &no_of_displays);

    vector <int> text_size(no_of_displays + 1);
    for(int i = 1; i <= no_of_displays; i++) scanf("%d", &text_size[i]);

    vector <int> cost(no_of_displays + 1);
    for(int i = 1; i <= no_of_displays; i++) scanf("%d", &cost[i]);

    const long long oo = 1e10;
    vector <long long> best_left(no_of_displays + 1, oo);
    vector <long long> best_right(no_of_displays + 1, oo);

    long long best_cost = oo;

    for(int mid = 1; mid <= no_of_displays; mid++)
    {
        for(int right = mid + 1; right <= no_of_displays; right++)
        {
            if(text_size[mid] < text_size[right])
                best_right[mid] = min(best_right[mid], cost[right]);
        }

        for(int left = 1; left < mid; left++)
        {
            if(text_size[left] < text_size[mid])
                best_left[mid] = min(best_left[mid], cost[left]);
        }

        best_cost = min(best_cost, best_right[mid] + cost[mid] + best_left[mid]);
    }

    printf(best_cost >= oo ? "-1\n" : "%I64d\n", best_cost);
    return 0;
}
