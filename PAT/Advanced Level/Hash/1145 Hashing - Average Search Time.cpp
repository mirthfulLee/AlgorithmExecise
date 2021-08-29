#include<iostream>
#include<vector>
using namespace std;

int MSize, N, M, TSize, temp, table[10500], pos, flag, cnt;

bool isPrime(int a) {
	for (int i = 2;i * i <= a;i++) {
		if (a % i == 0) return false;
	}
	return true;
}
int main() {
	cin >> MSize >> N >> M;
	TSize = MSize;
	while (!isPrime(TSize)) TSize++;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		flag = 0;
		for (int j = 0;j < TSize;j++) {
			pos = (temp + j * j) % TSize;
			if (!table[pos]) {
				flag = 1;
				table[pos] = temp;
				break;
			}
		}
		if (!flag) {
			printf("%d cannot be inserted.\n", temp);
		}
	}
	cnt = 0;
	for (int i = 0;i < M;i++) {
		cin >> temp;
		for (int j = 0;j <= TSize;j++) {
			cnt++;
			pos = (temp + j * j) % TSize;
			if (table[pos] == temp || !table[pos]) break;
		}
	}
	printf("%.1lf", cnt * 1.0 / M);
}