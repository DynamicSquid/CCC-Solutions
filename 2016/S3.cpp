#include <stdio.h>
#include <vector>
using namespace std;

bool pho[100000] = { false };
vector<int> list[100000];

bool prune(int num, int prev)
{
    for (int v : list[num])
    {
        if (v != prev && prune(v, num))
            pho[num] = true;
    }

    return pho[num];
}

int max_dist = 0, end_dist = 0;
void dist(int num, int prev, int d)
{
    if (d > max_dist)
    {
        max_dist = d;
        end_dist = num;
    }

    for (int v : list[num])
    {
        if (v != prev && pho[v])
            dist(v, num, d + 1);
    }
}

int main()
{
    int N, M;
    scanf("%i %i", &N, &M);

    int num;
    for (int a = 0; a < M; ++a)
    {
        scanf("%d", &num);
        pho[num] = true;
    }

    for (int a = 0; a < N - 1; ++a)
    {
        int x, y;
        scanf("%i %i", &x, &y);

        list[x].push_back(y);
        list[y].push_back(x);
    }

    prune(num, -1);

    dist(num, -1, 0);
    dist(end_dist, -1, 0);

    int nodes = 0;
    for (int a = 0; a < N; ++a)
    {
        if (pho[a])
            nodes++;
    }

    printf("%d", 2 * (nodes - 1) - max_dist);
}
