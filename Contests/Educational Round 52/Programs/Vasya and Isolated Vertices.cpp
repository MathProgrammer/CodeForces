#include <iostream>

#define max(a, b) (a > b ? a : b)

using namespace std;

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    long long vertices, edges;
    cin >> vertices >> edges;

    int minimum_isolated_vertices = max(0, vertices - 2*edges);

    long long i = 0;
    while(choose_2(i) <= edges)
        i++;

    int fully_connected_component = (choose_2(i - 1) == edges ? i - 1 : i);
    int maximum_isolated_vertices = vertices - fully_connected_component;

    cout << minimum_isolated_vertices << " " << maximum_isolated_vertices << "\n";

    return 0;
}
