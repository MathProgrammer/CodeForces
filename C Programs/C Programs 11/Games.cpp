#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_teams;
    scanf("%d", &no_of_teams);

    vector <int> home_uniform(no_of_teams + 1);
    map <int, int> no_of_guest_uniforms;
    for(int i = 1; i <= no_of_teams; i++)
    {
        int guest_uniform;
        scanf("%d %d", &home_uniform[i], &guest_uniform);

        no_of_guest_uniforms[guest_uniform]++;
    }

    int no_of_changes = 0;
    for(int i = 1; i <= no_of_teams; i++)
    {
        no_of_changes += no_of_guest_uniforms[home_uniform[i]];
    }

    printf("%d\n", no_of_changes);
    return 0;
}
