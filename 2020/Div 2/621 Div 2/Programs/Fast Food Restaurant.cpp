#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_bit_set(int n, int bit)
{
    return ( (n&(1 << bit)) != 0) ;
}

void solve()
{
    const int NO_OF_FOOD = 3;
    vector <int> portions(NO_OF_FOOD);
    for(int i = 0; i < NO_OF_FOOD; i++)
    {
        cin >> portions[i];
    }
    
    sort(all(portions));
    reverse(all(portions));
    
    int max_mask = (1 << NO_OF_FOOD);
    int no_of_meals = 0;
    
    for(int m = 1; m < max_mask; m++)
    {
        int good_mask = true;
        for(int i = 0; i < NO_OF_FOOD; i++)
        {
            if(is_bit_set(m, i) && portions[i] <= 0)
            {
                good_mask = false;
            }
        }
        
        if(!good_mask)
        {
            continue;
        }
       
        for(int i = 0; i < NO_OF_FOOD; i++)
        {
            if(is_bit_set(m, i))
            {
                portions[i]--;
            }
        }
        
        no_of_meals++;
    }
    
    cout << no_of_meals << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
