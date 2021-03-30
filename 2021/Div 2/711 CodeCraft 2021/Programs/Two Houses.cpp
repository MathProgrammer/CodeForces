#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    vector <int> indegree(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> indegree[i];
    }

    vector < pair <int, pair <int, int> > > edges;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        for(int j = i + 1; j <= no_of_vertices; j++)
        {
            int weight = abs(indegree[i] - indegree[j]);

            pair <int, int> E = make_pair(i, j);

            edges.push_back(make_pair(weight, E));
        }
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    int answer_u = 0, answer_v = 0;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first, v = edges[i].second.second;

        if(indegree[u] > indegree[v])
        {
            swap(u, v);
        }

        cout << "? " << v << " " << u << "\n";
        cout.flush();

        string reply;
        cin >> reply;

        if(reply[0] == 'Y')
        {
            answer_u = u; answer_v = v;
            break;
        }
    }

    cout << "! " << answer_u << " " << answer_v << "\n";
    return 0;
}
