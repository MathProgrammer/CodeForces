#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct customer
{
    int time, left, right;

    customer(){}
    
    customer(int T, int L, int R)
    {
        time = T; left = L; right = R;
    }
};

int sort_by_time(customer &A, customer &B)
{
    if(A.time == B.time)
    {
        return (A.left < B.left);
    }
    
    return (A.time < B.time);
}

void solve()
{
    int no_of_customers, starting;
    cin >> no_of_customers >> starting;
    
    vector <customer> C(no_of_customers, customer(0, 0, 0));
    for(int i = 0; i < no_of_customers; i++)
    {
        cin >> C[i].time >> C[i].left >> C[i].right;
    }
    
    sort(all(C), sort_by_time);
    
    int minimum = starting, maximum = starting;
    int possible = true;
    
    for(int i = 0; i < no_of_customers && possible; i++)
    {
        if(i == 0)
        {
            minimum = starting - C[i].time;
            maximum = starting + C[i].time;
        }
        else
        {
            minimum = minimum - (C[i].time - C[i - 1].time);
            maximum = maximum + (C[i].time - C[i - 1].time);
        }
        
        if(minimum > C[i].right || maximum < C[i].left)
        {
            possible = false;
            break;
        }
        
        minimum = max(minimum, C[i].left);
        maximum = min(maximum, C[i].right);
    }
    
    cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
