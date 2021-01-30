#include <stdio.h>
#include <queue>
using namespace std;

struct Step
{
    int x, y, s;
};

int main()
{
    int N, M, x, y;
    scanf("%i %i", &N, &M);

    char grid[105][105];
    bool invalid[105][105];
    int dots[105][105];

    for (int a = 0; a < N; ++a)
    {
        for (int b = 0; b < M; ++b)
        {
            char ch;
            scanf(" %c", &ch);

            if (ch == 'S')
            {
                x = b;
                y = a;
            }

            grid[a][b] = ch;
            dots[a][b] = ch == '.' ? -1 : 0;
            invalid[a][b] = false;
        }
    }

    for (int a = 0; a < N; ++a)
    {
        for (int b = 0; b < M; ++b)
        {
            if (grid[a][b] == 'C')
            {
                grid[a][b] = 'W';
                
                for (int c = b + 1; c < M && grid[a][c] != 'W'; ++c)
                {
                    if (grid[a][c] == '.' || grid[a][c] == 'S')
                        invalid[a][c] = true;
                }

                for (int c = b - 1; c >= 0 && grid[a][c] != 'W'; --c)
                {
                    if (grid[a][c] == '.' || grid[a][c] == 'S')
                        invalid[a][c] = true;
                }

                for (int c = a + 1; c < N && grid[c][b] != 'W'; ++c)
                {
                    if (grid[c][b] == '.' || grid[c][b] == 'S')
                        invalid[c][b] = true;
                }

                for (int c = a - 1; c >= 0 && grid[c][b] != 'W'; --c)
                {
                    if (grid[c][b] == '.' || grid[c][b] == 'S')
                        invalid[c][b] = true;
                }
            }
        }
    }

    queue<Step> visit;
    visit.push({ x, y, 0 });
    while (!visit.empty())
    {
        int vx = visit.front().x;
        int vy = visit.front().y;
        int vs = visit.front().s;

        if (grid[vy][vx] == 'U')
        {
            grid[vy][vx] = 'W';
            visit.front().y--;
            continue;
        }
        if (grid[vy][vx] == 'D')
        {
            grid[vy][vx] = 'W';
            visit.front().y++;
            continue;
        }
        if (grid[vy][vx] == 'L')
        {
            grid[vy][vx] = 'W';
            visit.front().x--;
            continue;
        }
        if (grid[vy][vx] == 'R')
        {
            grid[vy][vx] = 'W';
            visit.front().x++;
            continue;
        }

        visit.pop();

        if (grid[vy][vx] == 'W' || invalid[vy][vx])
            continue;

        if (grid[vy][vx] == '.')
            dots[vy][vx] = vs;

        visit.push({ vx + 1, vy,     vs + 1 });
        visit.push({ vx - 1, vy,     vs + 1 });
        visit.push({ vx,     vy + 1, vs + 1 });
        visit.push({ vx,     vy - 1, vs + 1 });

        grid[vy][vx] = 'W';
    }

    for (int a = 0; a < N; ++a)
    {
        for (int b = 0; b < M; ++b)
        {
            if (dots[a][b])
                printf("%i\n", dots[a][b]);
        }
    }
}
