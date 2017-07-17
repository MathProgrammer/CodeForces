#include <cstdio>

int main()
{
	int no_of_cubes, height;
	scanf("%d", &no_of_cubes);

	for(height = 1; ; height++)
	{
		no_of_cubes -= (height*(height + 1))/2;

        if(no_of_cubes < 0)
            break;
	}

	height--;
	printf("%d\n", height);
	return 0;
}
