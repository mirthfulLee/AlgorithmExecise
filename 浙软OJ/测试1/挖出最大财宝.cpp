#include <iostream>
using namespace std;

int m, n, v[100][100], flag[100][100], max_v=-1, t;

int dfs(int i, int j)
{
	if (flag[i][j] || v[i][j]<=0 || i<0||i>=m||j<0||j>=n)
		return 0;
	flag[i][j] = 1;
	return v[i][j] + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == -1)
			{
				if (i - 1 >= 0)
					v[i - 1][j] = 0;
				if (i + 1 < m)
					v[i + 1][j] = 0;
				if (j - 1 >= 0)
					v[i][j - 1] = 0;
				if (j + 1 < n)
					v[i][j + 1] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!flag[i][j]){
				t = dfs(i, j);
				if (t > max_v)
					max_v = t;
			}
		}
	}
	cout << max_v;
}