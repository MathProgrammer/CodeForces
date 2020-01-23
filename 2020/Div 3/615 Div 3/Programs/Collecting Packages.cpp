#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct point
{
    int x, y;
    
    point(){};
};

int sort_by_x(point &P, point &Q)
{
    if(P.x == Q.x)
    {
        return (P.y < Q.y);
    }
    
    return (P.x < Q.x);
}

void solve()
{
    int no_of_points;
    cin >> no_of_points;
    
    vector <point> P(no_of_points);
    for(int i = 0; i < no_of_points; i++)
    {
        cin >> P[i].x >> P[i].y;
    }
    
    sort(all(P), sort_by_x);
    
    int y_is_sorted = true;
    for(int i = 1; i < no_of_points; i++)
    {
        if(P[i - 1].y > P[i].y)
        {
            y_is_sorted = false;
            break;
        }
    }
    
    if(!y_is_sorted)
    {
        cout << "NO\n";
        return;
    }
    
    string answer;
    for(int x = 0, y = 0, i = 0; i < no_of_points; i++)
    {
        while(x != P[i].x)
        {//cout << "Right\n" << answer << "\n";
            answer += "R";
            x++;
        }
        
        while(y != P[i].y)
        {   //cout << "Up\n" << answer << "\n";
            answer += "U";
            y++;
        }
    }
    
    cout << "YES\n";
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
