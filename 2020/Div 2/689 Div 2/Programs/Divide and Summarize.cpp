#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <long long> A(MAX_N, 0), sum(MAX_N, 0);

long long get_sum(int left, int right)
{
    return (sum[right] - sum[left - 1]);
}

void check(map <long long, int> &S, int left, int right)
{
    S[get_sum(left, right)] = true;
    
    if(A[left] == A[right])
    {
        return;
    }
    
    int middle_element = (A[left] + A[right])/2;
    
    //Points to last occurrence of middle_element
    int mid = upper_bound(A.begin() + left, A.begin() + right, middle_element) - A.begin() - 1;
    
    check(S, left, mid);
    check(S, mid + 1, right);
}

void solve()
{
    int no_of_elements, no_of_queries;
    cin >> no_of_elements >> no_of_queries;
    
    A[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin() + 1, A.begin() + no_of_elements + 1);
    
    sum[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum[i] = sum[i - 1] + A[i];
    }
    
    map <long long, int> possible_sums;
    check(possible_sums, 1, no_of_elements);
    
    while(no_of_queries--)
    {
        long long target_sum;
        cin >> target_sum;
        
        cout << (possible_sums.count(target_sum) > 0 ? "Yes" : "No") << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
