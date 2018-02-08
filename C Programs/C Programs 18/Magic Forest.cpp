#include <cstdio>

int is_nondegenerate_triangle(int a, int b, int c)
{
    return (a + b > c);
}

int main()
{
    int n;
    scanf("%d", &n);

    int no_of_triangles = 0;
    for(int a = 1; a <= n; a++)
    {
        for(int b = a; b <= n; b++)
        {
            int c = a^b;

            if(c >= b && c <= n && is_nondegenerate_triangle(a, b, c))
                no_of_triangles++;
        }
    }

    printf("%d\n", no_of_triangles);
}
