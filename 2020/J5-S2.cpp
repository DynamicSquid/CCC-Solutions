#include <stdio.h>
#include <vector>
using namespace std;

int M, N;
bool been[1000][1000] = { false };
int grid[1000][1000];
vector<int> cells[1000001];

void walk(int x, int y)
{
    if (x == N - 1 && y == M - 1)
        throw 0;
    
    for (int num : cells[grid[y][x]])
    {
		int num1 = num - 1;
		int num2 = grid[y][x] / num - 1;

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

int main()
{
    scanf("%i %i", &M, &N);

    for (int a = 0; a < M; ++a)
    {
        for (int b = 0; b < N; ++b)
        {
            scanf("%i", &grid[a][b]);
			cells[(a + 1) * (b + 1)].push_back(a + 1);
			cells[(a + 1) * (b + 1)].push_back(b + 1);
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