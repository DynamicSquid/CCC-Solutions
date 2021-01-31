#include <stdio.h>

int main()
{
	int M;
	scanf("%i", &M);

	int friends[100][2] = { 0 };
	for (int a = 0, t = 0; a < M; ++a, ++t)
	{
		char type;
		int num;
		scanf(" %c %i", &type, &num);

		if (type == 'R')
		{
			friends[num][0] = t;
		}
		else if (type == 'S')
		{
			friends[num][1] += t - friends[num][0];
			friends[num][0] = 0;
		}
		else if (type == 'W')
		{
			t += num - 2;
		}
	}

	for (int a = 0; a < 100; ++a)
	{
		if (friends[a][0] == 0 && friends[a][1] != 0)
			printf("%i %i\n", a, friends[a][1]);
		else if (friends[a][0] != 0)
			printf("%i -1\n", a);
	}
}