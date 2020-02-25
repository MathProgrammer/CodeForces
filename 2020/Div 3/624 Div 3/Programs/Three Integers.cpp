#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    const int oo = 1e9, LIMIT = 4e4;
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int best_moves = oo;
    int x = a, y = b, z = c;
    
    for(int i = 1; i <= LIMIT; i++)
    {
        for(int j = i; j <= LIMIT; j += i)
        {
            for(int k = j; k <= LIMIT; k += j)
            {
                int moves_here = abs(i - a) + abs(j - b) + abs(k - c);
                
                if(moves_here < best_moves)
                {
                    best_moves = moves_here;
                    
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }
    
    cout << best_moves << "\n";
    cout << x << " " << y << " " << z << "\n";
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
