#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main()
{
    int no_of_drives, file_size;
    scanf("%d %d", &no_of_drives, &file_size);

    vector <int> capacity(no_of_drives);
    for(int i = 0; i < no_of_drives; i++)
        scanf("%d", &capacity[i]);

    sort(all(capacity));

    int no_of_drives_used = 0;
    for(int drive_i = no_of_drives - 1; file_size > 0 && drive_i >= 0; drive_i--, no_of_drives_used++)
        file_size -= capacity[drive_i];

    printf("%d\n", no_of_drives_used);
    return 0;
}
