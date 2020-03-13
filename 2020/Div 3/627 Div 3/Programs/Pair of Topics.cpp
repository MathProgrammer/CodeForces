#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

const int MAX_N = 1e6 + 5;
int sum_tree[3*MAX_N];

void update(int n, int left, int right, int position, int value)
{
    if(position < left || right < position)
    {
        return;
    }
    
    if(left == right)
    {
        sum_tree[n] += value;
        
        return;
    }
    
    int mid = (left + right)/2;
    
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);
    
    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < left || query_right < left || right < query_left)
    {
        return 0;
    }
    
    if(query_left <= left && right <= query_right)
    {
        return sum_tree[n];
    }
    
    int mid = (left + right)/2;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);
    
    return (left_sum + right_sum);
}

int main()
{
    int no_of_topics;
    cin >> no_of_topics;
    
    vector <int> A(no_of_topics + 1);
    for(int i = 1; i <= no_of_topics; i++)
    {
        cin >> A[i];
    }
    
    vector <int> B(no_of_topics + 1);
    for(int i = 1; i <= no_of_topics; i++)
    {
        cin >> B[i];
    }
    
    vector <long long> value(no_of_topics + 1);
    vector <long long> sorted_value;
    for(int i = 1; i <= no_of_topics; i++)
    {
        value[i] = A[i] - B[i];
        
        sorted_value.push_back(value[i]);
        
        sorted_value.push_back(-value[i]);
    }
    
    sort(all(sorted_value));
    
    map <long long, int> effective_index;
    for(int i = 0; i < sorted_value.size(); i++)
    {
        if(i == 0)
        {
            effective_index[sorted_value[i]] = 1;
        }
        else if(sorted_value[i] != sorted_value[i - 1])
        {
            effective_index[sorted_value[i]] = effective_index[sorted_value[i - 1]] + 1;
        }
    }
    
    long long no_of_good_pairs = 0;
    
    memset(sum_tree, 0, sizeof(sum_tree));
    
    for(int i = 1; i <= no_of_topics; i++)
    {
        no_of_good_pairs += get_sum(1, 1, 2*no_of_topics, effective_index[-value[i]] + 1, 2*no_of_topics);
    
        update(1, 1, 2*no_of_topics, effective_index[value[i]], 1);
    }
    
    cout << no_of_good_pairs << "\n";
    
    return 0;
}
