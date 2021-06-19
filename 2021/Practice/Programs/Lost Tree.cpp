#include <iostream>
#include <vector>

using namespace std;

void ask(int v, vector <int> &D, int n)
{
    cout << "? " << v << "\n";
    cout.flush();

    for(int i = 1; i <= n; i++)
    {
        cin >> D[i];
    }
}

void add_neighbours(int v, vector <int> &D, vector <vector <int> > &T)
{
    for(int i = 2; i < D.size(); i++)
    {
        if(D[i] == 1)
        {
            T[v].push_back(i);
        }
    }
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    vector <vector <int> > tree(no_of_vertices + 1);
    vector <vector <int> > parity(2);

    vector <int> distance(no_of_vertices + 1);

    ask(1, distance, no_of_vertices);
    add_neighbours(1, distance, tree);

    for(int i = 2; i <= no_of_vertices; i++)
    {
        parity[distance[i]%2].push_back(i);
    }

    vector <int> chosen = (parity[0].size() < parity[1].size() ? parity[0] : parity[1]);

    for(int v : chosen)
    {
        ask(v, distance, no_of_vertices);
        add_neighbours(v, distance, tree);
    }

    cout << "!\n";
    for(int i = 1; i <= no_of_vertices; i++)
    {
        for(int v : tree[i])
        {
            cout << i << " " << v << "\n";
        }
    }

    return 0;
}
