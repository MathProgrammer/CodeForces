#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Point
{
    int x, y;

    Point(){}

    Point(int X, int Y)
    {
        x = X, y = Y;
    }
};


const int NO_OF_NEIGHBOURS = 4, MAX_N = 55, oo = 1e9;
int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0 , 1};
int next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
int component_no[MAX_N][MAX_N], is_water[MAX_N][MAX_N];

int calculate_distance(Point P, Point Q)
{
    return (P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y);
}

int is_outside(int x, int y, int n)
{
    return (x < 1 || n < x || y < 1 || n < y);
}

void dfs(int x, int y, int n, int number)
{
    if(is_water[x][y] || is_outside(x, y, n) || component_no[x][y] != 0)
        return;

    component_no[x][y] = number;

    for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
    {
        dfs(x + next_x[i], y + next_y[i], n, number);
    }
}

int main()
{
    int n;
    cin >> n;

    Point start, finish;
    cin >> start.x >> start.y >> finish.x >> finish.y;

    memset(is_water, false, sizeof(is_water));
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;

        for(int j = 0; j < n; j++)
        {
            if(row[j] == '1')
            {
                is_water[i + 1][j + 1] = true;
            }
        }
    }

    memset(component_no, 0, sizeof(component_no));
    int last_component_no = 0;
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            if(component_no[x][y] == 0)
            {
                dfs(x, y, n, ++last_component_no);
            }
        }
    }

    vector <Point> start_component, finish_component;
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            if(component_no[x][y] == component_no[start.x][start.y])
                start_component.push_back(Point(x, y));

            if(component_no[x][y] == component_no[finish.x][finish.y])
                finish_component.push_back(Point(x, y));
        }
    }

    int distance = oo;
    for(int i = 0; i < start_component.size(); i++)
    {
        for(int j = 0; j < finish_component.size(); j++)
        {
            distance = min(distance, calculate_distance(start_component[i], finish_component[j]));
        }
    }

    cout << distance;
    return 0;
}
