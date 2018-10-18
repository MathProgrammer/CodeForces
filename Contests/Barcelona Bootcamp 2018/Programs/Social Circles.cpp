#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_guests;
    scanf("%d", &no_of_guests);

    vector <int> left(no_of_guests + 1, 0), right(no_of_guests + 1, 0);
    for(int i = 1; i <= no_of_guests; i++)
        scanf("%d %d", &left[i], &right[i]);

    sort(all(left));
    sort(all(right));

    long long no_of_chairs = 0;
    for(int i = 1; i <= no_of_guests; i++)
        no_of_chairs += max(left[i], right[i]) + 1;

    printf("%I64d\n", no_of_chairs);
    return 0;
}
