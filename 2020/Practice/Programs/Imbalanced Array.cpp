#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void compute_max_borders(int n, vector <int> &A, vector <int> &L, vector <int> &R)
{
    const int oo = 1e9 + 9;
    
    stack < pair <int, int> > left_max;
    left_max.push(make_pair(0, oo));
    for(int i = 1; i <= n; i++)
    {
        while(left_max.top().second < A[i])
        {
            left_max.pop();
        }
        
        L[i] = left_max.top().first + 1; //Range in which A[i] is maximum
        
        left_max.push(make_pair(i, A[i]));
    }
    
    stack < pair <int, int> > right_max;
    right_max.push(make_pair(n + 1, oo));
    for(int i = n; i >= 1; i--)
    {
        while(right_max.top().second <= A[i])
        {
            right_max.pop();
        }
        
        R[i] = right_max.top().first - 1;
        
        right_max.push(make_pair(i, A[i]));
        
    }
}

void compute_min_borders(int n, vector <int> &A, vector <int> &L, vector <int> &R)
{
    const int oo = 1e9 + 9;
    
    stack < pair <int, int> > left_min;
    left_min.push(make_pair(0, -oo));
    for(int i = 1; i <= n; i++)
    {
        while(left_min.top().second > A[i])
        {
            left_min.pop();
        }
        
        L[i] = left_min.top().first + 1; //cout << "L " << i << " = " << L[i] << "\n";
        
        left_min.push(make_pair(i, A[i]));
    }
    
    stack < pair <int, int> > right_min;
    right_min.push(make_pair(n + 1, -oo));
    for(int i = n; i >= 1; i--)
    {
        while(right_min.top().second >= A[i])
        {
            right_min.pop();
        }
        
        R[i] = right_min.top().first - 1;
        
        right_min.push(make_pair(i, A[i]));
    }
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> left_max_border(no_of_elements + 1), right_max_border(no_of_elements + 1);
    compute_max_borders(no_of_elements, A, left_max_border, right_max_border);
    
    long long total_maximum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long left_half = i - left_max_border[i], right_half = (right_max_border[i] - i);
        long long no_of_maximas = (left_half + 1)*(right_half + 1);
        
        total_maximum += no_of_maximas*A[i];
    }
    
    vector <int> left_min_border(no_of_elements + 1), right_min_border(no_of_elements + 1);
    compute_min_borders(no_of_elements, A, left_min_border, right_min_border);
    
    long long total_minimum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long left_half = i - left_min_border[i], right_half = right_min_border[i] - i;
        long long no_of_minima = (left_half + 1)*(right_half + 1);
        
        total_minimum += no_of_minima*A[i];
    }
    
    long long answer = total_maximum - total_minimum;
    
    cout << answer << "\n";
    
    return 0;
}
