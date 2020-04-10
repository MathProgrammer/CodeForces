#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector <int> largest_divisor(n + 1, 1);
    for(int i = 1; i <= n; i++)
    {
        for(int multiple = 2*i; multiple <= n; multiple += i)
        {
            largest_divisor[multiple] = i;
        }
    }
    
    sort(largest_divisor.begin(), largest_divisor.end());
    for(int i = 2; i <= n; i++)
    {
        cout << largest_divisor[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
