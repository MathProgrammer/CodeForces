#include <iostream>
#include <vector>
#include <map>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> min_tree(3*MAX_N + 5, 0);

void update(int n, int left, int right, int position, int value)
{
    if(right < position || position < left)
    {
        return;
    }
    
    if(left == right)
    {
        min_tree[n] = value;
        return;
    }
    
    int mid = (left + right)/2;
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);
    
    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

int get_first_smaller(int n, int left, int right, int x)
{
    if(min_tree[n] > x)
    {
        return -1;
    }
    
    if(left == right)
    {
        return left;
    }
    
    int mid = (left + right)/2;
    
    if(min_tree[LEFT(n)] < x)
    {
        return get_first_smaller(LEFT(n), left, mid, x);
    }
    
    return get_first_smaller(RIGHT(n), mid + 1, right, x);
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
    
    map <int, int> last;
    vector <int> is_mex(no_of_elements + 10, false);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(last[A[i]] + 1 != i)
        {
            int mex_here = get_first_smaller(1, 1, MAX_N, last[A[i]] + 1);
            
            //cout << "Mex[" << last[A[i]] + 1 << "," << i - 1 << "] = " << mex_here << "\n";
            
            is_mex[mex_here] = true;
        }
        
        last[A[i]] = i;
        
        update(1, 1, MAX_N, A[i], i);
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(last[A[i]] != no_of_elements)
        {
            int suffix_mex = get_first_smaller(1, 1, MAX_N, last[A[i]] + 1);
            
            //cout << "Suffix Mex[" << last[A[i]] + 1 << "," << no_of_elements << "] = " << suffix_mex << "\n";
            is_mex[suffix_mex] = true;
        }
    }
    
    int array_mex = get_first_smaller(1, 1, MAX_N, 1);
    is_mex[array_mex] = true;
    
    //cout << "Array Mex = " << array_mex << "\n";
    
    int final_mex = 0;
    for(int i = 1; i < is_mex.size(); i++)
    {
        if(!is_mex[i])
        {
            final_mex = i;
            break;
        }
    }
    
    cout << final_mex << "\n";
    return 0;
}
