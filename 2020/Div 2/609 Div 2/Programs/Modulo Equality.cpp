#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int add_and_check_equality(vector <int> A, vector <int> B, int m, int x)
{
    for(int i = 1; i < A.size(); i++)
    {
        A[i] = (A[i] + x)%m;
    }
    
    sort(all(A));
    
    for(int i = 1; i < B.size(); i++)
    {
        if(A[i] != B[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int no_of_elements, m;
    cin >> no_of_elements >> m;
    
    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        A[i] %= m;
    }
    
    vector <int> B(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
        
        B[i] %= m;
    }
    
    sort(all(B));
    
    int minimum_moves = m;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int to_add = (B[i] - A[1] + m)%m;
        
        if(add_and_check_equality(A, B, m, to_add))
        {
            minimum_moves = min(minimum_moves, to_add);
        }
    }
    
    cout << minimum_moves << "\n";
    return 0;
}
