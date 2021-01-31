#include <stdio.h>

int M, N;
bool been[1000][1000];
int grid[1000][1000];

void walk(int x, int y)
{
    if (x == N - 1 && y == M - 1)
        throw 0;
    
    for (int a = 1; a * a <= grid[y][x]; ++a)
    {
        if (grid[y][x] % a == 0)
        {
            int num1 = a - 1;
            int num2 = grid[y][x] / a - 1;

            if (num1 < M && num2 < N && !been[num1][num2])
            {
                been[num1][num2] = true;
                walk(num2, num1);
            }
            if (num2 < M && num1 < N && !been[num2][num1])
            {
                been[num2][num1] = true;
                walk(num1, num2);
            }
        }
    }
}

int main()
{
    scanf("%i %i", &M, &N);

    for (int a = 0; a < M; ++a)
    {
        for (int b = 0; b < N; ++b)
        {
            scanf("%i", &grid[a][b]);
            been[a][b] = false;
        }
    }

    been[0][0] = true;

    try {
        walk(0, 0);
        printf("no");
    }
    catch (...) {
        printf("yes");
    }
}