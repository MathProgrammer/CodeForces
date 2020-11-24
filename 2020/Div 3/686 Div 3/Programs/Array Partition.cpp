#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
#define all(v) (v).begin(), (v).end()
using namespace std;

struct node
{
    long long sum, minimum, maximum, lazy;
    
    node()
    {
        sum = 0; lazy = 0;
    }
    
    node(long long S, long long Min, long long Max)
    {
        sum = S; minimum = Min; maximum = Max;
        lazy = 0;
    }
};

node merge(node L, node R)
{
    return node(L.sum + R.sum, min(L.minimum, R.minimum), max(L.maximum, R.maximum));
}

const int MAX_N = 3e5 + 5, oo = 1e9 + 9;
vector <int> indices[MAX_N];
vector <int> A(MAX_N);
node tree[3*MAX_N];

void update(int n, int left, int right, int query_left, int query_right, long long x)
{
    if(right < left || query_right < query_left || query_right < left || right < query_left)
    {
        return;
    }
    
    if(query_left <= left && right <= query_right)
    {
        tree[n] = node(x, x, x);
        return;
    }
    
    int mid = (left + right)/2;
    
    update(LEFT(n), left, mid, query_left, query_right, x);
    update(RIGHT(n), mid + 1, right, query_left, query_right, x);
    
    tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

node get(int n, int left, int right, int query_left, int query_right)
{
    if(right < left || query_right < query_left || query_right < left || right < query_left)
    {
        return node(0, oo, 0);
    }
    
    if(query_left <= left && right <= query_right)
    {
        return tree[n];
    }
    
    int mid = (left + right)/2;
    
    return merge(get(LEFT(n), left, mid, query_left, query_right),
                 get(RIGHT(n), mid + 1, right, query_left, query_right));
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> sorted_A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        sorted_A[i] = A[i];
        
        indices[i].clear();
    }
    
    sort(sorted_A.begin(), sorted_A.end());
    
    map <int, int> label;
    label[sorted_A[1]] = 1;
    for(int i = 2; i <= no_of_elements; i++)
    {
        label[sorted_A[i]] = (sorted_A[i] == sorted_A[i - 1] ? label[sorted_A[i - 1]] : label[sorted_A[i - 1]] + 1);
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        A[i] = label[A[i]]; //cout << A[i] << " ";
        
        update(1, 1, no_of_elements, i, i, A[i]);
        
        indices[A[i]].push_back(i);
    }
    
    
    vector <int> left_border(no_of_elements + 1);
    stack <pair <int, int> > left_S;
    left_S.push(make_pair(0, 0));
    for(int i = 1; i <= no_of_elements; i++)
    {
        while(left_S.top().first >= A[i])
        {   //cout << left_S.top().first << " is greater than " << i << "\n";
            left_S.pop();
        }
        
        left_border[i] = left_S.top().second + 1; //cout << "Left " << i << " is " << left_border[i] << "\n";
        
        left_S.push(make_pair(A[i], i));
    }
        
    stack <pair <int, int> > right_S;
    vector <int> right_border(no_of_elements + 1);
    right_S.push(make_pair(0, no_of_elements + 1));
    for(int i = no_of_elements; i >= 1; i--)
    {
        while(right_S.top().first >= A[i])
        {
            right_S.pop();
        }
        
        right_border[i] = right_S.top().second - 1; //cout << "Right " << i << " = " << right_border[i] << "\n";
        
        right_S.push(make_pair(A[i], i));
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {   //cout << "For " << i << " is minimum in [" << left_border[i] << " " << right_border[i] << "]\n";
        if(indices[A[i]].size() < 3)
        {
            continue;
        }
        
        int p = lower_bound(all(indices[A[i]]), i) - indices[A[i]].begin() - 1;
        int s = lower_bound(all(indices[A[i]]), i) - indices[A[i]].begin() + 1;
        int prefix = A[p], suffix = A[s];
        //cout << "p = " << indices[A[i]][p] << " s = " << indices[A[i]][s] << "\n";
        int left_possible = false;
        
        while(p >= 0)
        {
            prefix = max(indices[A[i]][p], left_border[i] - 1);
            
            if(get(1, 1, no_of_elements, 1, prefix).maximum == A[i])
            {
                left_possible = true;
                break;
            }
            
            p--;
        }
        
        if(!left_possible)
        {
            continue;
        }
        
        int right_possible = false;
        
        while(s < indices[A[i]].size())
        {
            suffix = min(right_border[i] + 1, indices[A[i]][s]);
            
            if(get(1, 1, no_of_elements, suffix, no_of_elements).maximum == A[i])
            {
                right_possible = true;
                break;
            }
                
            s++;
        }
        
        if(!right_possible)
        {
            continue;
        }
        
        int part_1 = prefix, part_2 = (suffix - 1) - prefix;
        int part_3 = no_of_elements - (part_1 + part_2);
        
        cout << "YES\n";
        cout << part_1 << " " << part_2 << " " << part_3 << "\n";
        
        return;
    }
    
    cout << "NO\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
    {
        solve();
    }
    
    return 0;
}
