#include <stdio.h>

int main()
{
    int N;
    scanf("%i", &N);
    
    int right = 0, left = 0, top = 0, bottom = 0;
    for (int a = 0; a < N; ++a)
    {
        int x, y;
        scanf("%i %*c %i", &x, &y);
        
        if (!a)
        {
            right = x + 1;
            left = x - 1;
            top = y + 1;
            bottom = y - 1;
        }
        else
        {
            if (x <= left)
                left = x - 1;
            else if (x >= right)
                right = x + 1;
              
            if (y >= top)
                top = y + 1;
            else if (y <= bottom)
                bottom = y - 1;
        }
    }
    
    printf("%i,%i\n%i,%i", left, bottom, right, top);
}