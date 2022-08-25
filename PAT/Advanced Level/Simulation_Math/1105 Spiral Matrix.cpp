// 1105 Spiral Matrix
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, row, col, p, q, curDict, matrix[1010][1010], direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool mycmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num.begin(), num.end(), mycmp);
    col = sqrt(n);
    while (n % col)
        col--;
    row = n / col;
    curDict = 0;
    p = 0;
    q = -1;
    for (int i = 0; i < n; i++)
    {
        int nextP = p + direction[curDict][0], nextQ = q + direction[curDict][1];
        if (!(nextP >= 0 && nextP < row && nextQ >= 0 && nextQ < col && matrix[nextP][nextQ] == 0))
        {
            curDict = (curDict + 1) % 4;
            nextP = p + direction[curDict][0];
            nextQ = q + direction[curDict][1];
        }
        matrix[nextP][nextQ] = num[i];
        p = nextP;
        q = nextQ;
    }
    for (int i = 0; i < row;i++){
        printf("%d", matrix[i][0]);
        for (int j = 1; j < col;j++)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}