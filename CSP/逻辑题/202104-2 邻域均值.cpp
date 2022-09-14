// 	202104-2 邻域均值
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, l, r, t, cnt=0, cur;
    cin >> n >> l >> r >> t;
    vector<vector<int>> sum(n+1, vector<int> (n+1));
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++){
            cin >> cur;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cur;
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            int x1,y1,x2,y2, size, blockSum;
            x1 = max(1, i - r);
            y1 = max(1, j - r);
            x2 = min(n, i + r);
            y2 = min(n, j + r);
            size = (y2 - y1 + 1) * (x2 - x1 + 1);
            blockSum = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
            if (blockSum <= size * t)
                cnt++;
        }
    cout << cnt;
}