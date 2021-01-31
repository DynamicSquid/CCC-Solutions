#include <stdio.h>

int main()
{
    int N;
    scanf("%i", &N);

    long long buckets[2001] = { 0 };
    long long sums[4001] = { 0 };

    for (int a = 0; a < N; ++a)
    {
        int num;
        scanf("%i", &num);
        buckets[num]++;
    }

    for (int a = 1; a < 2001; ++a)
    {
        if (buckets[a])
        {
            sums[a + a] += buckets[a] / 2;
            
            for (int b = a + 1; b < 2001; ++b)
            {
                if (buckets[b] != 0)
                    sums[a + b] += buckets[a] < buckets[b] ? buckets[a] : buckets[b];
            }
        }
    }

    long long len = 0, num = 0;
    for (int a = 1; a <= 4000; ++a)
    {
        if (sums[a] > len)
        {
            len = sums[a];
            num = 1;
        }
        else if (sums[a] == len)
        {
            num++;
        }
    }

    printf("%lld %lld", len, num);
}