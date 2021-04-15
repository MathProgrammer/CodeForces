#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> graph[MAX_N];
vector <int> colour(MAX_N);
vector <int> component(MAX_N);
vector <int> component_graph[MAX_N];

int ceil(int n, int d)
{
    return (n/d) + (n%d != 0);
}

void dfs_component(int v, int parent_v, int component_no)
{
    component[v] = component_no;

    for(int child_v : graph[v])
    {
        if(child_v != parent_v && colour[child_v] == colour[v])
        {
            dfs_component(child_v, v, component_no);
        }
    }
}

int get_component_graph_diameter(int n)
{
    const int oo = 1e9;

    /*for(int i = 1; i <= n; i++)
    {
        cout << "Children of " << i << " : ";

        for(int child_v : component_graph[i])
        {
            cout << child_v << " ";
        }

        cout << "\n";
    }*/

    int root = 1;
    vector <int> distance(n + 1, oo);
    distance[root] = 0;

    queue <int> Q;
    Q.push(root);
    while(Q.size() > 0)
    {
        int v = Q.front(); Q.pop();

        for(int child_v : component_graph[v])
        {
            if(distance[v] + 1 < distance[child_v])
            {
                distance[child_v] = distance[v] + 1;
                Q.push(child_v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(distance[i] > distance[root])
        {
            root = i;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        distance[i] = oo;
    }
    distance[root] = 0;

    Q.push(root);
    while(Q.size() > 0)
    {
        int v = Q.front(); Q.pop();

        for(int child_v : component_graph[v])
        {   //cout << child_v << " is a child of " << v << "\n";
            if(distance[v] + 1 < distance[child_v])
            {
                distance[child_v] = distance[v] + 1;
                Q.push(child_v);
            }
        }
    }

    int diameter = 0;
    for(int i = 1; i <= n; i++)
    {
        diameter = max(diameter, distance[i]); //cout << "Component " << i << " has distance " << distance[i] << "\n";
    }

    return diameter;
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> colour[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int component_no = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(component[i] == 0)
        {
            dfs_component(i, 0, ++component_no);
        }
    }

    for(int i = 1; i <= no_of_vertices; i++)
    {
        for(int child : graph[i])
        {
            int child_component = component[child], this_component = component[i];

            if(child_component != this_component)
            {   //cout << "Edge " << child_component << " and " << this_component << "\n";
                component_graph[this_component].push_back(child_component);
                component_graph[child_component].push_back(this_component);
            }
        }
    }

    int diameter = get_component_graph_diameter(component_no);

    int answer = ceil(diameter, 2);

    cout << answer << "\n";
    return 0;
}
