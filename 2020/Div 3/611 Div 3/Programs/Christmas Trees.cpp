#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_trees, no_of_people;
    cin >> no_of_trees >> no_of_people;
    
    vector <int> X(no_of_trees);
    for(int i = 0; i < no_of_trees; i++)
    {
        cin >> X[i];
    }
    
    map <int, int> distance;
    queue <int> Q;
    for(int i = 0; i < no_of_trees; i++)
    {
        Q.push(X[i]);
        
        distance[X[i]] = 0;
    }
    
    long long total_distance = 0;
    vector <int> people;
    while(!Q.empty() && people.size() < no_of_people)
    {
        int current = Q.front();
        Q.pop();
        
        if(distance[current] != 0)
        {
            total_distance += distance[current];
            
            people.push_back(current);
        }
        
        if(distance.count(current + 1) == 0)
        {
            distance[current + 1] = distance[current] + 1;
            
            Q.push(current + 1);
        }
        
        if(distance.count(current - 1) == 0)
        {
            distance[current - 1] = distance[current] + 1;
            
            Q.push(current - 1);
        }
    }
    
    cout << total_distance << "\n";
    for(int i = 0; i < no_of_people; i++)
    {
        cout << people[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
