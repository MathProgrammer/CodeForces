#include <cstdio>
#include <vector>
using namespace std;

void count(vector <int> &no_of_ways, int group, int LIMIT)
{
	const int MOD = 1e9 + 7;
	no_of_ways[0] = 1;

	for(int i = 1; i < LIMIT; i++)
	{
		if(i < group)
			no_of_ways[i] = 1;
		else
			no_of_ways[i] = (no_of_ways[i - 1] + no_of_ways[i - group])%MOD;
	}
}

int main()
{
	int no_of_queries, group;
	scanf("%d %d", &no_of_queries, &group);

	const int LIMIT = 1e5 + 1, MOD = 1e9 + 7;
	vector <int> no_of_ways(LIMIT, 0);

	count(no_of_ways, group, LIMIT);

	vector <int> no_of_ways_till(LIMIT, 0);
	for(int i = 1; i < LIMIT; i++)
		no_of_ways_till[i] = (no_of_ways_till[i - 1] + no_of_ways[i])%MOD;

	while(no_of_queries--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", (no_of_ways_till[b] - no_of_ways_till[a - 1] + MOD)%MOD);
	}

	return 0;
}
