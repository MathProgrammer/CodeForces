#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> indices[MAX_N];
vector <int> A(MAX_N);

void compress_coordinates(int no_of_elements)
{
    vector <int> sorted_A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sorted_A[i] = A[i];
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
        
        indices[A[i]].push_back(i);
    }
}

void compute_prefix_and_suffix_max(int no_of_elements, vector <int> &prefix_maximum, vector <int> &suffix_maximum)
{
   for(int i = 1; i <= no_of_elements; i++)
   {
       prefix_maximum[i] = max(prefix_maximum[i - 1], A[i]);
   }
   
   
   for(int i = no_of_elements; i >= 1; i--)
   {
       suffix_maximum[i] = max(suffix_maximum[i + 1], A[i]);
   }
}

void compute_borders(int no_of_elements, vector <int> &left_border, vector <int> &right_border)
{
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
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        indices[i].clear();
    }
    
    compress_coordinates(no_of_elements);
    
    vector <int> prefix_maximum(no_of_elements + 1);
    vector <int> suffix_maximum(no_of_elements + 5);
    compute_prefix_and_suffix_max(no_of_elements, prefix_maximum, suffix_maximum);
    
    vector <int> left_border(no_of_elements + 1);
    vector <int> right_border(no_of_elements + 1);
    compute_borders(no_of_elements, left_border, right_border);
    
    for(int i = 1; i <= no_of_elements; i++)
    {   //cout << "For " << i << " is minimum in [" << left_border[i] << " " << right_border[i] << "]\n";
        if(indices[A[i]].size() < 3 || i == indices[A[i]][0] || i == indices[A[i]].back())
        {
            continue;
        }
        
        if(prefix_maximum[left_border[i] - 1] > A[i] || suffix_maximum[right_border[i] + 1] > A[i])
        {
            continue;
        }
        
        int p = upper_bound(all(indices[A[i]]), left_border[i] - 2) - indices[A[i]].begin();
        if(indices[A[i]][p] == i)
        {
            p--;
        }
        
        int s = lower_bound(all(indices[A[i]]), right_border[i] - 1) - indices[A[i]].begin();
        if(s == indices[A[i]].size() || indices[A[i]][s] > right_border[i] + 1)
        {
            s--;
        }
        
        while(s < indices[A[i]].size() && indices[A[i]][s] <= i)
        {
            s++;
        }
        
        int prefix, suffix;
        //cout << "p = " << indices[A[i]][p] << " s = " << indices[A[i]][s] << "\n";
        int left_possible = false;
        
        while(p >= 0)
        {
            prefix = max(indices[A[i]][p], left_border[i] - 1);
            //cout << "Prefix = " << prefix << " Maximum = " << prefix_maximum[prefix] << "\n";
            if(prefix_maximum[prefix] == A[i])
            {
                left_possible = true;
                break;
            }
            
            if(p < left_border[i] - 1)
            {
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
            suffix = min(indices[A[i]][s], right_border[i] + 1);
            //cout << "Prefix = " << suffix<< " Maximum = " << suffix_maximum[suffix] << "\n";
            
            if(suffix_maximum[suffix] == A[i])
            {
                right_possible = true;
                break;
            }
            
            if(s > right_border[i] + 1)
            {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
    {
        solve();
    }
    
    return 0;
}
