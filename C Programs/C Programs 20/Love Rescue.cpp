#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 26;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);
vector <int> component[MAX_N] ;

void mark(int v, int component_no)
{
    visited[v] = true;
    component[component_no].push_back(v);

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(!visited[child])
            mark(child, component_no);
    }
}

int main()
{
    int length;
    string A, B;
    cin >> length >> A >> B;

    for(int i = 0; i < length; i++)
    {
        if(A[i] != B[i])
        {
            graph[A[i] - 'a'].push_back(B[i] - 'a');
            graph[B[i] - 'a'].push_back(A[i] - 'a');
        }
    }

    int component_no = 0, no_of_edges = 0;
    for(int i = 0; i < MAX_N; i++)
    {
        if(graph[i].size() != 0 && !visited[i])
        {
            mark(i, component_no);
            no_of_edges += component[component_no].size() - 1;

            component_no++;
        }
    }

    cout << no_of_edges << "\n";
    for(int i = 0; i < component_no; i++)
    {
        for(int j = 1; j < component[i].size(); j++)
        {
            cout << char('a' + component[i][j - 1]) << " " << char('a' + component[i][j]) << "\n";
        }
    }

    return 0;
}
