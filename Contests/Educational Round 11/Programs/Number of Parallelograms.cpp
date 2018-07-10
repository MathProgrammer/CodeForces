#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point
{
    int x, y;

    Point(int X, int Y)
    {
        x = X, y = Y;
    }

    //A binary search tree needs the elements to be ordered.
    int operator<(const Point &P) const //This needs to be overloaded for the map to work
    {
        return (x == P.x ? y < P.y : x < P.x);
    }
};

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    int no_of_points;
    cin >> no_of_points;

    vector <Point> P;
    for(int i = 1; i <= no_of_points; i++)
    {
        int x, y;
        cin >> x >> y;

        P.push_back(Point(x, y));
    }

    map <Point, int> frequency;
    for(int i = 0; i < no_of_points; i++)
    {
        for(int j = i + 1; j < no_of_points; j++)
        {
            //Avoid floating point errors so store (x1 + x2), (y1 + y2) rather than dividing.
            Point mid_point = Point( (P[i].x  + P[j].x), (P[i].y + P[j].y) );

            frequency[mid_point]++;
        }
    }

    long long answer = 0;
    for(map <Point, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        answer += choose_2(it->second);
    }

    cout << answer;

    return 0;
}
