#include <cstdio>
#include <vector>

using namespace std;

struct Point{

long long x, y;

};

int is_on_line(Point a, Point b, Point c)
{
    //Checking slope product to avoid division
    return ( (c.y - b.y)*(b.x - a.x) == (b.y - a.y)*(c.x - b.x) );
}

int check_line(vector <Point> &line)
{
    for(int i = 2; i < line.size(); i++)
        if(!is_on_line(line[0], line[1], line[i]))
            return false;

    return true;
}

int check_one_line_passing_through(int a, int b, vector <Point> &P)
{
    vector <Point> line_2;

    for(int i = 1; i < P.size(); i++)
    {
        if(!is_on_line(P[a], P[b], P[i]))
           line_2.push_back(P[i]);
    }

    int two_lines_possible = check_line(line_2);
    return two_lines_possible;
}

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    vector <Point> P(no_of_points + 1);
    for(int i = 1; i <= no_of_points; i++)
        scanf("%I64d %I64d", &P[i].x, &P[i].y);

    int two_lines_possible = (no_of_points <= 4 || check_one_line_passing_through(1, 2, P)
                              || check_one_line_passing_through(2, 3, P) || check_one_line_passing_through(3, 1, P));

    printf(two_lines_possible ? "YES\n" : "NO\n");
    return 0;
}
