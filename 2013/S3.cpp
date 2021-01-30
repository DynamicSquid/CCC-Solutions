#include <stdio.h>
#include <vector>
using namespace std;

int T, score = 0;

void play(vector<vector<int> > games, int (&points)[4])
{
    if (games.empty())
    {
        int max = 0;

        for (int a = 1; a < 4; ++a)
        {
            if (points[a] > points[max])
                max = a;
        }

        for (int a = 0; a < 4; ++a)
        {
            if (a != max && points[a] == points[max])
                return;
        }

        if (max == T - 1)
            score++;

        return;
    }

    int t1 = games.back()[0] - 1;
    int t2 = games.back()[1] - 1;
    games.pop_back();

    points[t1] += 3;
    play(games, points);
    points[t1] -= 3;

    points[t2] += 3;
    play(games, points);
    points[t2] -= 3;

    points[t1]++;
    points[t2]++;
    play(games, points);
    points[t1]--;
    points[t2]--;
}

int main()
{
    int G;
    scanf("%i %i", &T, &G);

    vector<vector<int> > games{
        { 1, 2 }, { 1, 3 }, { 1, 4 },
        { 2, 3 }, { 2, 4 },
        { 3, 4 }
    };

    int points[4] = { 0 };

    for (int a = 0; a < G; ++a)
    {
        int t1, t2, s1, s2;
        scanf("%i %i %i %i", &t1, &t2, &s1, &s2);

        for (int b = 0; b < (int)games.size(); ++b)
        {
            if ((games[b][0] == t1 && games[b][1] == t2) || (games[b][0] == t2 && games[b][1] == t1))
            {
                games.erase(games.begin() + b);
                break;
            }
        }

        if (s1 > s2)
        {
            points[t1 - 1] += 3;
        }
        else if (s1 < s2)
        {
            points[t2 - 1] += 3;
        }
        else
        {
            points[t1 - 1]++;
            points[t2 - 1]++;
        }
    }

    play(games, points);
    printf("%i", score);
}