#include <stdio.h>
#include <stdlib.h>

int cmp(const void* elem1, const void* elem2) 
{
    return *((int*)elem1) >= *((int*)elem2) ? 1 : 0;
}

int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main()
{
	int Q, N;
	scanf("%i %i", &Q, &N);

	int dmoj[100], peg[100];

	for (int a = 0; a < N; ++a)
		scanf("%i", &dmoj[a]);
	for (int a = 0; a < N; ++a)
		scanf("%i", &peg[a]);

	qsort(dmoj, N, sizeof(int), cmp);
	qsort(peg, N, sizeof(int), cmp);

	int spd = 0;
	for (int a = 0; a < N; ++a)
		spd += max(dmoj[a], Q == 1 ? peg[a] : peg[N - a - 1]);

	printf("%i", spd);
}