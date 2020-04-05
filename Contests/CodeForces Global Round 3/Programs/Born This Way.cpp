#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int A_to_B, B_to_C, time_A_to_B, time_B_to_C, deleted;
    cin >> A_to_B >> B_to_C >> time_A_to_B >> time_B_to_C >> deleted;
    
    vector <long long> A(A_to_B + 1);
    for(int i = 1; i <= A_to_B; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> B(B_to_C + 1);
    for(int i = 1; i <= B_to_C; i++)
    {
        cin >> B[i];
    }
    
    const long long oo = 1e15;
    long long max_time = (deleted >= A_to_B || deleted >= B_to_C ? oo : 0);
    A.push_back(oo);
    B.push_back(oo);
    
    for(int a_deletes = 0; a_deletes <= min(deleted, A_to_B - 1); a_deletes++)
    {
        long long reached_B = A[a_deletes + 1] + time_A_to_B;
        
        int first_b = upper_bound(B.begin(), B.end(), reached_B - 1) - B.begin();
        
        int b_deletes = deleted - a_deletes + first_b - 1;
        
        if(b_deletes > B_to_C)
        {
            max_time = oo;
            break;
        }
        
        max_time = max(max_time, B[b_deletes + 1] + time_B_to_C);
    }
    
    cout << (max_time >= oo ? -1 : max_time) << "\n";
    return 0;
}
