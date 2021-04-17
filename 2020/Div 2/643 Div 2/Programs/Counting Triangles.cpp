#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector <long long> no_of_starts(B + C + 5, 0), no_of_finishes(B + C + 5, 0);
    for(int x = A; x <= B; x++)
    {
        no_of_starts[x + B]++;
        no_of_finishes[x + C + 1]++;
    }

    vector <long long> no_of_ways(B + C + 5, 0);
    for(int i = B; i <= B + C; i++)
    {
        no_of_ways[i] = no_of_ways[i - 1] + no_of_starts[i] - no_of_finishes[i];
    }

    vector <long long> suffix_sum(B + C + 5, 0);
    for(int i = B + C; i >= B; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + no_of_ways[i];
    }

    long long no_of_triangles = 0;
    for(int z = C; z <= min(D, B + C); z++)
    {
        no_of_triangles += suffix_sum[z + 1];
    }

    cout << no_of_triangles << "\n";
    return 0;
}
