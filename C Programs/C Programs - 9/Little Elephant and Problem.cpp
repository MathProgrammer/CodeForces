#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> original_array(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &original_array[i]);

    vector <int> sorted_array = original_array;

    sort(all(sorted_array));

    int differences = 0;
    for(int i = 0; i < no_of_elements; i++)
        differences += (sorted_array[i] != original_array[i]);

    printf(differences <= 2 ? "YES\n" : "NO\n");
    return 0;
}
