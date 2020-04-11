#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct Point
{
    int x, cost, duration, is_left;
    
    Point(){}
    
    Point(int X, int C, int D, int is_L)
    {
        x = X;
        cost = C;
        duration = D;
        is_left = is_L;
    }
};

int sort_by_point(Point &A, Point &B)
{
    if(A.x == B.x)
    {
        return (A.is_left && !B.is_left ? true : false);
    }
    
    return (A.x < B.x);
}

int main()
{
    int no_of_segments, total;
    cin >> no_of_segments >> total;
    
    vector <Point> A;
    for(int i = 1; i <= no_of_segments; i++)
    {
        int left, right, x;
        cin >> left >> right >> x;
        
        A.push_back(Point(left, x, right - left + 1, true));
        A.push_back(Point(right, x, right - left + 1, false));
    }
    
    sort(A.begin(), A.end(), sort_by_point);
    
    map <int, int> minimum_cost;
    const int oo = 2e9 + 7;
    int answer = oo;
    
    for(int i = 0; i < 2*no_of_segments; i++)
    {
        if(A[i].is_left)
        {
            if(minimum_cost.find(total - A[i].duration) != minimum_cost.end())
            {
                answer = min(answer, minimum_cost[total - A[i].duration] + A[i].cost);
            }
        }
        else
        {
            if(minimum_cost.find(A[i].duration) != minimum_cost.end())
            {
                minimum_cost[A[i].duration] = min(minimum_cost[A[i].duration], A[i].cost);
            }
            else
            {
                minimum_cost[A[i].duration] = A[i].cost;
            }
        }
    }
    
    cout << (answer >= oo ? -1 : answer) << "\n";
    
    return 0;
}
