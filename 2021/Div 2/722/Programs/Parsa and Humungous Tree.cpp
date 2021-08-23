#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5, MAX_ENDS = 2, L = 0, R = 1;
vector <int> tree[MAX_N];
long long maximum_at[MAX_N][MAX_ENDS], left_value[MAX_N], right_value[MAX_N];

void initialize(int no_of_vertices)
{
    for(int i = 1; i <= no_of_vertices; i++)
    {
        tree[i].clear();
        maximum_at[i][L] = maximum_at[i][R] = 0;
    }
}

void dfs(int v, int parent_v)
{
    for(int child_v : tree[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }

        dfs(child_v, v);

        long long using_left_value_at_child = abs(left_value[v] - left_value[child_v]) + maximum_at[child_v][L];
        long long using_right_value_at_child = abs(left_value[v] - right_value[child_v]) + maximum_at[child_v][R];

        maximum_at[v][L] += max(using_left_value_at_child, using_right_value_at_child);

        using_left_value_at_child = abs(right_value[v] - left_value[child_v]) + maximum_at[child_v][L];
        using_right_value_at_child = abs(right_value[v] - right_value[child_v]) + maximum_at[child_v][R];

        maximum_at[v][R] += max(using_left_value_at_child, using_right_value_at_child);
    }

    /*cout << "At " << v << " L = " << left_value[v] << " Maximum = " << maximum_at[v][L] << "\n";
    cout << "At " << v << " R = " << right_value[v] << " Maximum = " << maximum_at[v][R] << "\n";*/
}

void solve()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    initialize(no_of_vertices);

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> left_value[i] >> right_value[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    cout << max(maximum_at[1][L], maximum_at[1][R]) << "\n";
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
