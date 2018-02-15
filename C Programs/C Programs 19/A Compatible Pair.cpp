#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a_elements, b_elements;
    scanf("%d %d", &a_elements, &b_elements);

    vector <long long> A(a_elements);
    for(int i =0; i < a_elements; i++) scanf("%I64d", &A[i]);

    vector <long long> B(b_elements);
    for(int i = 0; i < b_elements; i++) scanf("%I64d", &B[i]);

    long long max_product = -1e18;
    int best_choice_A;
    for(int i = 0; i < a_elements; i++)
    {
        for(int j = 0; j < b_elements; j++)
        {
            if(A[i]*1LL*B[j] > max_product)
            {
                best_choice_A = i;
                max_product = A[i]*1LL*B[j];
            }
        }
    }

    long long max_product_without_best_A = -1e18;
    for(int i = 0; i < a_elements; i++)
    {
        if(i == best_choice_A)
            continue;

        for(int j = 0; j < b_elements; j++)
        {
            max_product_without_best_A = max(max_product_without_best_A, A[i]*1LL*B[j]);
        }
    }

    printf("%I64d\n", max_product_without_best_A);
    return 0;
}

