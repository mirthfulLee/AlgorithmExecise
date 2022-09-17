#include <stdio.h>
int main()
{
    int n, m, i, s = 0;
    printf("N M = ");
    scanf("%d%d", &n, &m);
    for (i = n; i > 1; i--)
    {
        s = (s + m + 1) % i;
    }
    printf("The winner is %d\n", s);
}