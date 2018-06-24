#include <vector>
#include <cstdio>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_exams;
    scanf("%d", &no_of_exams);

    vector <int> grade(no_of_exams);
    for(int i = 0; i < no_of_exams; i++) scanf("%d", &grade[i]);

    sort(all(grade));

    int sum = 0;
    for(int i = 0; i < no_of_exams; i++)
    {
        grade[i] *= 10;
        sum += grade[i];
    }

    int no_of_changes = 0, target = 45; //Rather than 4.5, we aim for 45.

    for(int i = 0; sum < target*no_of_exams && i < no_of_exams; i++)
    {
        sum += (50 - grade[i]); //Make grade[i] = 50

        no_of_changes++;
    }

    printf("%d\n", no_of_changes);
    return 0;
}

