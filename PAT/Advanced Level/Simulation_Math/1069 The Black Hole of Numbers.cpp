// 1069 The Black Hole of Numbers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, flag=0;
    vector<int> d(4);
    cin >> n;
    while (!flag || (n != 0 && n != 6174))
    {
        int x = n, a = 0, b = 0;
        for (int i = 0; i < 4; i++)
        {
            d[i] = x % 10;
            x /= 10;
        }
        sort(d.begin(), d.end());
        for (int i = 0; i < 4; i++)
        {
            a = a * 10 + d[i];
            b = b * 10 + d[3 - i];
        }
        n = b - a;
        printf("%04d - %04d = %04d\n", b, a, n);
        flag++;
    }
}