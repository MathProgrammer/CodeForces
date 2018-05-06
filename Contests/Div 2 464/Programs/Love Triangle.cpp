#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_planes;
    scanf("%d", &no_of_planes);

    vector <int> liked_by(no_of_planes + 1);
    for(int i = 1; i <= no_of_planes; i++)
        scanf("%d", &liked_by[i]);

    int love_triangle_exists = false;
    for(int i = 1; i <= no_of_planes; i++)
    {
        int a = i;
        int b = liked_by[a];
        int c = liked_by[b];

        if(a == liked_by[c])
        {
            love_triangle_exists = true;
        }
    }

    printf(love_triangle_exists ? "YES\n" : "NO\n");
    return 0;
}
