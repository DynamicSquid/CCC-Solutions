#include <stdio.h>

int main()
{
    int s, m, l;
    scanf("%i %i %i", &s, &m, &l);

    printf(s + (2 * m) + (3 * l) >= 10 ? "happy" : "sad");
}