#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
   int x, y, limit, k, sum;
   scanf("%d %d %d",&y, &k, &limit);

   vector <int> possibilities;
   int no_of_possibilities = 0;

   for(sum = k, x = sum - y; sum <= limit; sum += k, x = sum - y)
   {
       if(x > 0)
       {
           no_of_possibilities++;
           possibilities.push_back(x);
       }

    }

   if(no_of_possibilities == 0)
        printf("-1\n");
   else
        for(int i = 0; i < no_of_possibilities; i++)
            printf("%d\t",possibilities[i]);

    return 0;
}
