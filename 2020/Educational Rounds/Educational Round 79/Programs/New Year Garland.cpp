#include <iostream>

using namespace std;

long long max_3(long long a, long long b, long long c)
{
    return max(a, max(b, c));
}

void solve()
{
    long long red, green, blue;
    cin >> red >> green >> blue;
    
    long long total = red + green + blue;
    long long maximum = max_3(red, green, blue);
    long long remaining_sum = total - maximum;
    
    cout << (maximum <= remaining_sum + 1 ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
