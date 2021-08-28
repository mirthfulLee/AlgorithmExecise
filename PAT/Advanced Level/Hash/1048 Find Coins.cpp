#include<iostream>
using namespace std;

int cnt[1005];
int main() {
	int N, M, temp;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		cnt[temp]++;
	}
	for (int i = 0;i < M / 2 + M % 2;i++) {
		if (cnt[i] && cnt[M - i]) {
			printf("%d %d", i, M - i);
			return 0;
		}
	}
	if (M % 2 == 0 && cnt[M / 2] > 1) {
		printf("%d %d", M / 2, M / 2);
		return 0;
	}
	printf("No Solution");
	return 0;
}