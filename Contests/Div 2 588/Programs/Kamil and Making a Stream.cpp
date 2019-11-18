#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX_N = 1e5 + 5, MOD = 1e9 + 7;

long long answer;
vector <int> tree[MAX_N];
vector <int> visited(MAX_N, 0);
vector <long long> value(MAX_N, 0);

long long gcd(long long x, long long y)
{
    if(min(x, y) == 0)
        return max(x, y);
    else
        return gcd(max(x, y)%min(x, y), min(x,y));
}

void dfs(int v, map <long long, int> frequency)
{
    visited[v] = true;

    map <long long, int> new_frequency;

    for(map <long long, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        new_frequency[gcd(value[v], it->first)] += it->second;
    }

    new_frequency[value[v]]++;

    for(map <long long, int> :: iterator it = new_frequency.begin(); it != new_frequency.end(); it++)
    {
        answer += (it->first)*(it->second);

        answer %= MOD;
    }

    for(int i = 0; i < tree[v].size(); i++)
    {
        int child = tree[v][i];

        if(visited[child])
        {
           continue;
        }

        dfs(child, new_frequency);
    }
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> value[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    map <long long, int> frequency;
    dfs(1, frequency);

    cout << answer << "\n";

    return 0;
}
