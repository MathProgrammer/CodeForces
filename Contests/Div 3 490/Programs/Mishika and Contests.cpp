#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_problems, skill;
    scanf("%d %d", &no_of_problems, &skill);

    vector <int> difficulty(no_of_problems + 1);
    for(int i = 1; i <= no_of_problems; i++) scanf("%d", &difficulty[i]);

    int solvable = 0;
    int left = 1, right = no_of_problems;
    while( (difficulty[left] <= skill || difficulty[right] <= skill) && left <= right)
    {
        if(difficulty[left] <= skill)
            left++, solvable++;
        else if(difficulty[right] <= skill)
            right--, solvable++;
    }

    printf("%d\n", solvable);
    return 0;
}
