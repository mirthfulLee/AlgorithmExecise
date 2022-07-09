#include<iostream>
#include<vector>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int INF = 9999;
	vector<vector<int>> dis = {
		{5,1,6,1,5,8,6},
		{2,4,3,2,4,1,3},
		{4,8,2,6,2,2,2},
		{6,3,4,4,5,5,1},
		{2,5,6,1,4,3,6}
	};
	int y[10][10];
	int sX[10][10], sY[10][10];
	sX[0][0] = 0; sY[0][0] = 0;
	for (int i = 0;i <= 5;i++)
		for (int j = 0;j <= 6;j++)
			y[i][j] = INF;
	y[0][0] = 2 * dis[0][0];
	for (int i = 1; i < 6; i++)
	{
		y[0][i] = dis[0][i] + y[0][i - 1];
		sX[0][i] = 0;
		sY[0][i] = i - 1;
	}
	for (int i = 1;i < 5;i++) {
		y[i][0] = dis[i][0] + y[i - 1][0];
		sX[i][0] = i - 1;
		sY[i][0] = 0;
		for (int j = 1;j < 6;j++) {
			int d = dis[i][j];
			if (y[i - 1][j] + d < y[i][j]) {
				y[i][j] = y[i - 1][j] + d;
				sX[i][j] = i - 1;
				sY[i][j] = j;
			}
			if (y[i - 1][j - 1] + 2 * d < y[i][j]) {
				y[i][j] = y[i - 1][j - 1] + 2 * d;
				sX[i][j] = i - 1;
				sY[i][j] = j - 1;
			}
			if (y[i][j - 1] + d < y[i][j]) {
				y[i][j] = y[i][j - 1] + d;
				sX[i][j] = i;
				sY[i][j] = j - 1;
			}
		}
	}

	printf("shortest match value:%d\n", y[4][5]);
	int a = 4, b = 5;
	printf("path: [5, 6] <- ");
	while (a > 0 || b > 0) {
		printf("[%d, %d] <- ", sX[a][b] + 1, sY[a][b] + 1);
		int temp = sY[a][b];
		a = sX[a][b];
		b = temp;
	}
	printf("[0, 0]");
}