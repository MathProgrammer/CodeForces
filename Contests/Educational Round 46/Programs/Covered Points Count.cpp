#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

typedef long long LL;

struct info
{
    LL location;
    int new_segments;

    info(LL loc = 0, int new_seg = 0)
    {
        location = loc;
        new_segments = new_seg;
    }

    const operator <(info &A)
    {
        return (location < A.location);
    }
};

int main()
{
    int no_of_segments;
    scanf("%d", &no_of_segments);

    vector <info> edge(2*no_of_segments + 1);
    edge[0] = info(0, 0);
    for(int i = 1; i <= no_of_segments; i++)
    {
        LL left, right;
        scanf("%I64d %I64d", &left, &right);

        edge[2*i - 1] = info(left, 1);
        edge[2*i] = info(right + 1, -1);
    }

    sort(all(edge));

    vector <LL> points_covered_by(no_of_segments + 1, 0);
    int no_of_covering_lines = 0;

    for(int i = 1; i <= 2*no_of_segments; i++)
    {
        points_covered_by[no_of_covering_lines] += edge[i].location - edge[i - 1].location;

        no_of_covering_lines += edge[i].new_segments;
    }

    for(int i = 1; i <= no_of_segments; i++)
        printf("%I64d ", points_covered_by[i]);

    return 0;
}
