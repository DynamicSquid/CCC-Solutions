#include <stdio.h>
#include <deque>
using namespace std;

int main()
{
    int T;
    scanf("%i", &T);

    for (int a = 0; a < T; ++a)
    {
        int N;
        scanf("%i", &N);

        deque<int> cars(N);
        for (int b = N - 1; b >= 0; --b)
            scanf("%i", &cars[b]);

        deque<int> branch;
        int curr = 1;

        for (int b = 0; b < (int)cars.size(); ++b)
        {
            if (cars[b] == curr)
            {
                curr++;
            }
            else if (!branch.empty() && branch.front() == curr)
            {
                branch.pop_front();
                curr++;
                b--;
            }
            else
            {
                branch.push_front(cars[b]);
            }
        }

        for (int num : branch)
        {
            if (num == curr)
                curr++;
        }

        printf(curr - 1 == N ? "Y\n" : "N\n");
    }
}