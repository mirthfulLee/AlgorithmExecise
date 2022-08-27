// 202206-1 归一化处理
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double a[1010], sum = 0, mean, squareD = 0, D;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    mean = 1.0 * sum / n;
    for (int i = 0; i < n; i++)
    {
        squareD += (a[i] - mean) * (a[i] - mean);
    }
    D = sqrt(squareD/n);
    for (int i = 0; i < n; i++)
        printf("%.16f\n", (a[i] - mean) / D);
}