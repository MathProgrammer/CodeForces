#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

void solve()
{
    int no_of_vertices, no_of_edges, k;
    cin >> no_of_vertices >> no_of_edges >> k;
    
    vector <unordered_set <int> > graph(no_of_vertices + 1);
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].insert(v);
        graph[v].insert(u);
    }
    
    vector <int> is_active(no_of_vertices + 1, true);
    set <pair <int, int> > degree;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        degree.insert(make_pair(graph[i].size(), i));
    }
    
    int subset_found = false, clique = false;
    for(set <pair <int, int> > :: iterator it = degree.begin(); degree.size() > 0; )
    {
        it = degree.begin();
        
        if( (*it).first >= k )
        {
            subset_found = true;
            break;
        }
        
        if( (*it).first == k - 1 && 2LL*no_of_edges >= k*1LL*(k - 1))
        {
            clique = (*it).second;
            vector <int> current_candidates;
            
            current_candidates.push_back(clique);
            for(unordered_set <int> :: iterator it_1 = graph[clique].begin(); clique && it_1 != graph[clique].end(); it_1++)
            {
                current_candidates.push_back(*it_1);
            }
            
            for(int i = 0; i < current_candidates.size() && clique != false; i++)
            {
                for(int j = i + 1; j < current_candidates.size(); j++)
                {
                    if(graph[current_candidates[i]].count(current_candidates[j]) == 0)
                    {
                        clique = false;
                        break;
                    }
                }
            }
                       
            if(clique)
            {
                break;
            }
        }
        
        int v = (*it).second;
        
        for(unordered_set <int> :: iterator it = graph[v].begin(); it != graph[v].end(); it++)
        {
            int u = *it;
            
            degree.erase(make_pair(graph[u].size(), u));
            graph[u].erase(v);
            degree.insert(make_pair(graph[u].size(), u));
        }
        
        no_of_edges -= (*it).first;
        degree.erase(it);
    }
    
    if(subset_found)
    {
        cout << "1 " << degree.size() << "\n";
        
        for(set <pair <int, int> > :: iterator it = degree.begin(); it != degree.end(); it++)
        {
            cout << (*it).second << " ";
        }
        
        cout << "\n";
        
        return;
    }
    
    if(clique)
    {
        cout << "2\n";
        cout << clique << " ";
        
        for(unordered_set <int> :: iterator it = graph[clique].begin(); it != graph[clique].end(); it++)
        {
            cout << (*it) << " ";
        }
        
        cout << "\n";
        
        return;
    }
    
    cout << "-1\n";
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
