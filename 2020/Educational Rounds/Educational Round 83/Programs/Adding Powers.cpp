#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> power;
    power.push_back(1);
    
    while(power.back() <= 1e16/k)
    {
        power.push_back(power.back()*k);
    }
    
    int possible = true;
    map <long long, int> used;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long x = A[i];
        
        for(int p = power.size() - 1; p >= 0 && x > 0; p--)
        {   //cout << "X = " << x << " P = " << power[p] << "\n";
            if(x < power[p])
            {
                continue;
            }
            
            if(used[p])
            {
                possible = false;
                break;
            }
            
            x -= power[p];
            
            if(x >= power[p])
            {
                possible = false;
                break;
            }
            
            used[p] = true;
        }
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
