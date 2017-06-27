#include <cstdio>
#include <algorithm>

#define min_3(a, b, c) min(a, min(b, c) )
#define max_3(a, b, c) max(a, max(b, c) )

using namespace std;

int main()
{
    int green, red, blue;
    scanf("%d %d %d",&red, &green, &blue);

    int one_mixed_boquet = 0, two_mixed_boquet = 0, no_mixed_boquet;

    no_mixed_boquet = red/3 + green/3 + blue/3;

    if(min_3(red,green, blue) >= 1)
        one_mixed_boquet = 1 + (red - 1)/3 + (green - 1)/3 + (blue - 1)/3;
    if(min_3(red, green, blue) >= 2)
        two_mixed_boquet = 2 + (red - 2)/3 + (green - 2)/3 + (blue - 2)/3;

    printf("%d\n",max_3(no_mixed_boquet, two_mixed_boquet, one_mixed_boquet));
    return 0;
}

