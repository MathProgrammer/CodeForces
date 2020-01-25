#include <iostream>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

using namespace std;

struct node
{
    int gcd, minimum, minimum_frequency;
    
    node(){}
    
    node(int G, int M, int F)
    {
        gcd = G; minimum = M; minimum_frequency = F;
    }
};

const int MAX_N = 1e5 + 5, oo = 1e9 + 9;
node tree[4*MAX_N];
int A[MAX_N];

int gcd(int a, int b)
{
    if(min(a, b) == 0)
    {
        return max(a, b);
    }
    
    return gcd(max(a, b)%min(a, b), min(a, b));
}

node merge(node &A, node &B)
{
    node C;
    
    C.gcd = gcd(A.gcd, B.gcd);
    
    if(A.minimum == B.minimum)
    {
        C.minimum = A.minimum;
        C.minimum_frequency = A.minimum_frequency + B.minimum_frequency;
    }
    else if(A.minimum < B.minimum)
    {
        C.minimum = A.minimum;
        C.minimum_frequency = A.minimum_frequency;
    }
    else if(B.minimum < A.minimum)
    {
        C.minimum = B.minimum;
        C.minimum_frequency = B.minimum_frequency;
    }
    
    return C;
}

void build(int n, int left, int right)
{
    if(left == right)
    {
        tree[n] = node(A[left], A[left], 1);
        return;
    }
    
    int mid = (left + right)/2;
    
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);
    
    tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

node query(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left || right < left)
    {
        return node(0, oo, 0);
    }
    
    if(query_left <= left && right <= query_right)
    {
        return tree[n];
    }
    
    int mid = (left + right)/2;
    
    node left_answer = query(LEFT(n), left, mid, query_left, query_right);
    node right_answer = query(RIGHT(n), mid + 1, right, query_left, query_right);
    
    //cout << " At " << left << "," << right << " LEFT answer(" << left << "," << mid <<") = " << left_answer.gcd << " RIGHT answer(" << mid + 1 << "," << right << ") = " << right_answer.gcd << "\n";
    return merge(left_answer, right_answer);
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    build(1, 1, no_of_elements);
    
    int no_of_queries;
    cin >> no_of_queries;
    
    while(no_of_queries--)
    {
        int left, right;
        cin >> left >> right;
        
        node answer = query(1, 1, no_of_elements, left, right);
        
        int free = 0;
        //cout << "GCD = " << answer.gcd << " " << "Minimum = " << answer.minimum << "\n";
        
        if(answer.gcd == answer.minimum)
        {
            free = answer.minimum_frequency;
        }
        
        int remaining = right - (left - 1) - free;
        
        cout << remaining << "\n";
    }
    
    return 0;
}
