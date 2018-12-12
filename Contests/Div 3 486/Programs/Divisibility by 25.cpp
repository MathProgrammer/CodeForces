#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int oo = 100;

int min_moves_for_suffix(string S, string suffix)
{
    int moves = oo;

    for(int first = 0; first < S.size(); first++)
    {
        for(int second = 0; second < S.size(); second++)
        {
            if(first == second)
                continue;

            string N = S;
            int moves_here = 0;

            for(int i = first; i < N.size() - 1.; i++)
            {
                swap(N[i], N[i + 1]);
                moves_here++;
            }

            //Second may have been disturbed by first
            for(int i = second - (second > first); i < N.size() - 2; i++)
            {
                swap(N[i], N[i + 1]);
                moves_here++;
            }

            int first_non_zero = 0;
            while(N[first_non_zero] == '0')
                first_non_zero++;

            for(int i = first_non_zero; i > 0; i--)
            {
                swap(N[i], N[i - 1]);
                moves_here++;
            }

            if(N[N.size() - 2] == suffix[0] && N[N.size() - 1] == suffix[1])
                moves = min(moves, moves_here);
        }
    }

    return moves;
}

int main()
{
    string N;
    cin >> N;

    int minimum_moves = oo;

    minimum_moves = min( min(min_moves_for_suffix(N, "25"), min_moves_for_suffix(N, "50")),
                         min(min_moves_for_suffix(N, "75"), min_moves_for_suffix(N, "00")) );

    cout << (minimum_moves >= oo ? -1 : minimum_moves);

    return 0;
}
