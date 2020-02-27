#include <iostream>

using namespace std;

void solve()
{
    int bus, tram, budget;
    cin >> bus >> tram >> budget;
    
    string city;
    cin >> city;
    
    int index = 0, money_so_far = 0;
    for(int i = city.size() - 2; i >= 0; i--)
    {
        if(i == city.size() - 2 || (city[i] != city[i + 1]))
        {
            int money_here = (city[i] == 'A' ? bus : tram);
            
            //cout << "Money at " << i + 1 << " = " << money_here << " T = " << money_so_far + money_here << "\n";
            if(money_so_far + money_here > budget)
            {
                index = (i + 1);
                break;
            }
            
            money_so_far += money_here;
        }
    }
    
    cout << index + 1 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
