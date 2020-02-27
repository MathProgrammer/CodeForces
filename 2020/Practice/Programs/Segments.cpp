#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int ENTRY = 1, EXIT = 2;

struct segment
{
    int point, type, index;
    
    segment(){}
    
    segment(int P, int T, int I)
    {
        point = P; type = T; index = I;
    }
};

int sort_by_left(segment &S_1, segment &S_2)
{
    if(S_1.point == S_2.point)
    {
        return (S_1.type < S_2.type);
    }
    
    return (S_1.point < S_2.point);
}

int main()
{
    int no_of_segments;
    cin >> no_of_segments;
  
    vector <segment> S;
    for(int i = 0; i < no_of_segments; i++)
    {
        int left, right;
        cin >> left >> right;
        
        if(left > right)
        {
            swap(left, right);
        }
        
        S.push_back(segment(left, ENTRY, i));
        S.push_back(segment(right, EXIT, i));
    }
    
    sort(all(S), sort_by_left);
    
    vector <int> already_handled(no_of_segments, false);
    vector <int> meeting_points;
    
    stack <int> handled_indices;
    
    for(int i = 0; i < 2*no_of_segments; i++)
    {
        if(already_handled[S[i].index])
        {
            continue;
        }
        
        if(S[i].type == ENTRY)
        {
            handled_indices.push(S[i].index);
        }
        else if(S[i].type == EXIT)
        {
            meeting_points.push_back(S[i].point);
            
            while(handled_indices.size() > 0)
            {
                already_handled[handled_indices.top()] = true;
                
                handled_indices.pop();
            }
        }
    }
    
    cout << meeting_points.size() << "\n";
    for(int i = 0; i < meeting_points.size(); i++)
    {
        cout << meeting_points[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
