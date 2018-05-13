#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    const int MAX = 1015;
    vector <int> used(MAX, false);
    vector <int> ans;

    for(int i = no_of_elements; i >= 1; i--)
    {
        if(!used[A[i]])
        {
            used[A[i]] = true;
            ans.push_back(A[i]);
        }
    }

    reverse(all(ans));

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);

    return 0;
}

