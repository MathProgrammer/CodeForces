#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;

struct Point
{
    int index;
    LL x, y;

    Point(LL a = 0, LL b = 0, int index = 0)
    {
        x = a, y = b, index = 0;
    }

    Point operator+(const Point &P)
    {
        return Point(x + P.x, y + P.y);
    }
    Point operator-(const Point &P)
    {
        return Point(x - P.x, y - P.y);
    }
};

LL square(LL n)
{
    return n*n;
}

LL square_norm(Point P)
{
    return (P.x*P.x + P.y*P.y);
}

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    vector <Point> V(no_of_points);
    for(int i = 0; i < no_of_points; i++)
    {
        scanf("%I64d %I64d", &V[i].x, &V[i].y);
        V[i].index = i;
    }

    const LL oo = 1.5e6;
    Point P;
    vector <int> step(no_of_points);

    do
    {
        random_shuffle(all(V));

        P = Point(0, 0);

        for(int i = 0; i < no_of_points; i++)
        {
            if(square_norm(P + V[i]) <= square_norm(P - V[i]))
            {
                P = P + V[i];
                step[V[i].index] = 1;
            }
            else
            {
                P = P - V[i];
                step[V[i].index] = -1;
            }
        }
    }
    while(square_norm(P) > square(oo));

    for(int i = 0; i < no_of_points; i++)
        printf("%d ", step[i]);

    return 0;
}
