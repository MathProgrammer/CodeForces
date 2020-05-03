#include <iostream>
#include <vector>
#include <set>

using namespace std;

int range, no_of_pairs;
vector <int> x, y;

int check_for_x(int n)
{
    int no_of_remaining_pairs = 0;
    vector <int> degree(range + 1, 0);
    for(int i = 1; i <= no_of_pairs; i++)
    {
        if(x[i] == n || y[i] == n)
        {
            continue;
        }
        
        degree[x[i]]++;
        degree[y[i]]++;
        
        no_of_remaining_pairs++;
    }
    
    for(int i = 1; i <= range; i++)
    {
        if(degree[i] == no_of_remaining_pairs)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    cin >> range >> no_of_pairs;
    
    x.resize(no_of_pairs + 1);
    y.resize(no_of_pairs + 1);
    for(int i = 1; i <= no_of_pairs; i++)
    {
        cin >> x[i] >> y[i];
    }
    
    cout << (check_for_x(x[1]) || check_for_x(y[1]) ? "YES\n" : "NO\n");
    return 0;
}
