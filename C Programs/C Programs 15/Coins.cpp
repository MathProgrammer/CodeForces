#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector <int> denominations;
	denominations.push_back(n);

	for(int i = 2; n > 1; i++)
	{
		while(n%i == 0)
		{
			n = n/i;
			denominations.push_back(n);
		}
	}

	for(int i = 0; i < denominations.size(); i++)
		printf("%d ", denominations[i]);

	return 0;
}
