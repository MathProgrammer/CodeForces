#include <cstdio>

int in_middle(int L, int x, int R)
{
    return ((L <= x && x <= R) || (R <= x && x <= L));
}

int main()
{
    int n, queen_x, queen_y, king_x, king_y, center_x, center_y;
    scanf("%d %d %d %d %d %d %d", &n, &queen_x, &queen_y, &king_x, &king_y, &center_x, &center_y);

    int queen_middle_x = in_middle(king_x, queen_x, center_x);
    int queen_middle_y = in_middle(king_y, queen_y, center_y);

    printf(queen_middle_x || queen_middle_y ? "NO\n" : "YES\n");
    return 0;
}
