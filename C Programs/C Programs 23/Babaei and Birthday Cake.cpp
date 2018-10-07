#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define all(v) (v).begin() + 1, (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 1e5 + 5;
double max_tree[3*MAX_N];

void insert(int n, int left, int right, double value, int position)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        max_tree[n] = value;
        return;
    }

    int mid = (left + right) >> 1;

    insert(LEFT(n), left, mid, value, position);
    insert(RIGHT(n), mid + 1, right, value, position);

    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

double get_max(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < query_left || query_right < left || right < query_left)
        return 0;

    if(query_left <= left && right <= query_right)
        return max_tree[n];

    int mid = (left + right) >> 1;
    double left_max = get_max(LEFT(n), left, mid, query_left, query_right);
    double right_max = get_max(RIGHT(n), mid + 1, right, query_left, query_right);

    return max(left_max, right_max);
}

int main()
{
    int no_of_cylinders;
    scanf("%d", &no_of_cylinders);

    vector <double> volume(no_of_cylinders + 1);
    vector <double> sorted_volume(no_of_cylinders + 1);
    for(int i = 1; i <= no_of_cylinders; i++)
    {
        int radius, height;
        scanf("%d %d", &radius, &height);

        const double PI = 3.14159;

        volume[i] = (PI*radius*radius*1LL*height);
        sorted_volume[i] = volume[i];
    }

    sort(all(sorted_volume));

    map <double, int> rank;
    for(int i = 1; i <= no_of_cylinders; i++)
        rank[sorted_volume[i]] = i;

    map <double, double> answer_with_last;

    for(int i = 1; i <= no_of_cylinders; i++)
    {
        answer_with_last[volume[i]] = volume[i] + get_max(1, 1, no_of_cylinders, 1, rank[volume[i]] - 1);

        insert(1, 1, no_of_cylinders, answer_with_last[volume[i]], rank[volume[i]]);
    }

    double answer = 0;
    for(int i = 1; i <= no_of_cylinders; i++)
        answer = max(answer, answer_with_last[volume[i]]);

    printf("%.10f\n", answer);
    return 0;
}
