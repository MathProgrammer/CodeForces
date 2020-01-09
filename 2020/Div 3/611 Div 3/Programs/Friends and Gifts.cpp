#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int no_of_friends;
    cin >> no_of_friends;
    
    vector <int> A(no_of_friends + 1);
    for(int i = 1; i <= no_of_friends; i++)
    {
        cin >> A[i];
    }
    
    vector <int> indegree(no_of_friends + 1);
    vector <int> outdegree(no_of_friends + 1);
    for(int i = 1; i <= no_of_friends; i++)
    {
        if(A[i] != 0)
        {
            indegree[A[i]]++;
            outdegree[i]++;
        }
    }
    
    vector <int> isolated_vertices;
    for(int i = 1; i <= no_of_friends; i++)
    {
        if(indegree[i] == 0 && outdegree[i] == 0)
        {
            isolated_vertices.push_back(i);
        }
    }
    
    if(isolated_vertices.size() == 1)
    {
        int v = isolated_vertices[0];
        
        for(int i = 1; i <= no_of_friends; i++)
        {
            if(indegree[i] == 0 && i != v)
            {
                A[v] = i;
                
                indegree[i]++;
                outdegree[v]++;
                
                break;
            }
        }
    }
    else if(isolated_vertices.size() > 1)
    {
        for(int i = 0; i < isolated_vertices.size(); i++)
        {
            int u = isolated_vertices[i], v = isolated_vertices[(i + 1)%isolated_vertices.size()];
            
            A[u] = v;
            indegree[v]++;
            outdegree[u]++;
        }
    }
    
    vector <int> empty_in;
    vector <int> empty_out;
    for(int i = 1; i <= no_of_friends; i++)
    {
        if(indegree[i] == 0)
        {
            empty_in.push_back(i);
        }
        if(outdegree[i] == 0)
        {
            empty_out.push_back(i);
        }
    }
    
    for(int i = 0; i < empty_out.size(); i++)
    {
        int u = empty_out[i], v = empty_in[i];
        
        A[u] = v;
    }
    
    for(int i = 1; i <= no_of_friends; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
