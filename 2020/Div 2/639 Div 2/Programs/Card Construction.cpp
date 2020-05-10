#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 1e9;
vector <long long> cards;

void precompute()
{
    cards.push_back(0);
    
    while(cards.back() < MAX_N)
    {
        int level = cards.size();
        
        long long next = 2*level + level - 1 + cards.back();
        
        cards.push_back(next);
    }
}

void solve()
{
    int n;
    cin >> n;
    
    int no_of_pyramids = 0;
    
    while(true)
    {
        int current_pyramid_size = lower_bound(all(cards), n) - cards.begin();
        
        if(cards[current_pyramid_size] > n)
        {
            current_pyramid_size--;
        }
        
        n -= cards[current_pyramid_size];
        
        if(current_pyramid_size == 0)
        {
            break;
        }
        
        no_of_pyramids++;
    }
    
    cout << no_of_pyramids << "\n";
}

int main()
{
    precompute();
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
