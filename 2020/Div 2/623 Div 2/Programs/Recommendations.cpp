#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_magazines;
    cin >> no_of_magazines;
    
    vector <pair <int, long long> > M(no_of_magazines);
    
    for(int i = 0; i < no_of_magazines; i++)
    {
        cin >> M[i].first;
    }
    
    for(int i = 0; i < no_of_magazines; i++)
    {
        cin >> M[i].second;
    }
    
    sort(all(M));
    
    multiset <long long> equal_segment;
    
    long long current_minima = 0, i = 0;
    
    long long total_cost = 0, equal_segment_sum = 0;
    while(i < M.size() || equal_segment.size() > 0)
    {
        while(i < M.size() && M[i].first == current_minima)
        {
            equal_segment.insert(M[i].second);
            equal_segment_sum += M[i].second;
            i++;
        }
        
        if(equal_segment.size() > 0)
        {
            auto it = equal_segment.rbegin();
            long long largest = *it;
            
            equal_segment.erase(equal_segment.find(largest)); //Erases only one instance of largest
            equal_segment_sum -= largest;
            
            total_cost += equal_segment_sum;
            
            current_minima++;
        }
        else
        {
            current_minima = M[i].first;
        }
    }
    
    cout << total_cost << "\n";
    return 0;
}
