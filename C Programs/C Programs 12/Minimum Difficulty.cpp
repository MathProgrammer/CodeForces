#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int number_of_holds;
    scanf("%d", &number_of_holds);

    vector <int> height(number_of_holds + 1);
    for(int i = 1; i <= number_of_holds; i++)
        scanf("%d", &height[i]);

    int original_difficulty = 0;
    for(int i = 2; i <= number_of_holds; i++)
        original_difficulty = max(original_difficulty, height[i] - height[i - 1]);

    const int oo = 1e4;
    int minimum_difficulty = oo;
    for(int i = 2; i <= number_of_holds - 1; i++)
    {
        int current_difficulty = max(original_difficulty, height[i + 1] - height[i - 1]);

        minimum_difficulty = min(current_difficulty, minimum_difficulty);
    }

    printf("%d\n", minimum_difficulty);
    return 0;
}
