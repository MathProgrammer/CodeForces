#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int blue, violet, orange;
    scanf("%d %d %d", &blue, &violet, &orange);

    int required_blue, required_violet, required_orange;
    scanf("%d %d %d", &required_blue, &required_violet, &required_orange);

    int no_of_new_spheres_possible = 0, no_of_new_spheres_needed = 0;

    no_of_new_spheres_needed = max(required_blue - blue, 0) + max(required_orange - orange, 0) + max(required_violet - violet, 0);

    no_of_new_spheres_possible = max( (blue - required_blue)/2, 0) + max( (orange - required_orange)/2, 0) + max( (violet - required_violet)/2, 0);

    printf(no_of_new_spheres_possible >= no_of_new_spheres_needed ? "Yes\n" : "No\n");
    return 0;
}
