#include <stdio.h>

int main()
{
    int P, N, R;
    scanf("%i %i %i", &P, &N, &R);

    int total = N, days = 0;
    for (; total <= P; ++days)
    {
        N *= R;
        total += N;
    }
  
    printf("%i", days);
}