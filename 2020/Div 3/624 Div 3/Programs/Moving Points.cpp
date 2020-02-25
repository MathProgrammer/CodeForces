#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

struct Point
{
    long long distance, velocity;
    
    Point(){};
    
    Point(long long D, long long V)
    {
        distance = D;
        velocity = V;
    }
};

int sort_by_distance(const Point &P, const Point &Q)
{
    return (P.distance < Q.distance);
}

const int MAX_N = 2e5 + 5;
pair <long long, int> sum_tree[3*MAX_N];

void update(int n, int left, int right, int position, long long value)
{
    if(position < left || right < position)
    {
        return;
    }
    
    if(left == right)
    {
        sum_tree[n].first += value;
        sum_tree[n].second++;
        
        //cout << "Sum Tree " << n << " = " << sum_tree[n].first << "," << sum_tree[n].second << "\n";
        
        return;
    }
    
    int mid = (left + right)/2;
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);
    
    sum_tree[n].second = sum_tree[LEFT(n)].second + sum_tree[RIGHT(n)].second;
    sum_tree[n].first = sum_tree[LEFT(n)].first + sum_tree[RIGHT(n)].first;
    
    //cout << "Sum Tree " << n << " = " << sum_tree[n].first << "," << sum_tree[n].second << "\n";
}

pair <long long, int> get(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left || query_right < query_left)
    {
        return make_pair(0, 0);
    }
    
    if(query_left <= left && right <= query_right)
    {
        return sum_tree[n];
    }
    
    int mid = (left + right)/2;
    pair <long long, int> left_answer = get(LEFT(n), left, mid, query_left, query_right);
    pair <long long, int> right_answer = get(RIGHT(n), mid + 1, right, query_left, query_right);
    
    pair <long long, int> answer;
    
    answer.second = left_answer.second + right_answer.second;
    answer.first = left_answer.first + right_answer.first;
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_points;
    cin >> no_of_points;
    
    vector <Point> P(no_of_points);
    for(int i = 0; i < no_of_points; i++)
    {
        cin >> P[i].distance;
    }
    
    for(int i = 0; i < no_of_points; i++)
    {
        cin >> P[i].velocity;
    }
    
    sort(all(P), sort_by_distance);
    
    vector <int> velocities;
    for(int i = 0; i < no_of_points; i++)
    {
        velocities.push_back(P[i].velocity);
    }
    
    sort(all(velocities));
    
    map <long long, int> effective_index;
    effective_index[velocities[0]] = 1;
    
    for(int i = 1; i < no_of_points; i++)
    {
        if(velocities[i] == velocities[i - 1])
        {
            continue;
        }
        
        effective_index[velocities[i]] = effective_index[velocities[i - 1]] + 1;
    }
    
    for(int i = 0; i < 3*MAX_N; i++)
    {
        sum_tree[i] = make_pair(0, 0);
    }
    
    long long answer = 0;
    
    for(int i = 0; i < no_of_points; i++)
    {
        pair <long long, int> Q = get(1, 1, no_of_points, 1, effective_index[P[i].velocity]);
        
        long long total = Q.first;
        int no_of_points_here = Q.second;
        
        //cout << "At x = " << P[i].distance << " V = " << P[i].velocity << "\n";
        //cout << "No of Points = " << no_of_points_here << " Total = " << total << "\n";
        //cout << "Range = [1, " << effective_index[P[i].velocity] - 1 << "]\n";
        
        answer += ( (no_of_points_here)*P[i].distance - total);
        
        //cout << "Answer = " << answer << "\n";
        update(1, 1, no_of_points, effective_index[P[i].velocity], P[i].distance);
    }
    
    cout << answer << "\n";
    return 0;
}
