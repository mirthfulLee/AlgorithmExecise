// 1073 Scientific Notation
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char numSign, expSign, firstDigit, cur;
    char fractPortion[10010];
    int exp, len;
    scanf("%c%c.", &numSign, &firstDigit);
    int p = 0;
    cur = getchar();
    while (cur != 'E')
    {
        fractPortion[p++] = cur;
        cur = getchar();
    }
    scanf("%c%d", &expSign, &exp);

    len = strlen(fractPortion);
    if (numSign == '-')
        printf("%c", numSign);
    if (exp == 0)
    {
        printf("%c", firstDigit);
        if (len)
            printf(".");
        for (int i = 0; i < len; i++)
            printf("%c", fractPortion[i]);
        return 0;
    }
    if (expSign == '+')
    {
        printf("%c", firstDigit);
        if (exp >= len)
        {
            for (int i = 0; i < len; i++)
                printf("%c", fractPortion[i]);

            for (int i = len; i < exp; i++)
                printf("%c", '0');
        }
        else
        {
            for (int i = 0; i < exp; i++)
                printf("%c", fractPortion[i]);
            printf("%c", '.');
            for (int i = exp; i < len; i++)
                printf("%c", fractPortion[i]);
        }
    }
    else
    {
        printf("0.");
        for (int i = 1; i < exp; i++)
            printf("%c", '0');
        printf("%c", firstDigit);
        for (int i = 0; i < len; i++)
            printf("%c", fractPortion[i]);
    }
}