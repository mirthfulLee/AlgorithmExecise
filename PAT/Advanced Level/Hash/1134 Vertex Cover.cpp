#include<iostream>
#include<algorithm>
using namespace std;

int N, M, K, num, temp, flag, a[10010], b[10010], h[10010];

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++)
		scanf("%d %d", &a[i], &b[i]);
	cin >> K;
	for (int t = 0;t < K;t++) {
		cin >> num;
		fill(h, h + N, 0);
		for (int i = 0;i < num;i++) {
			scanf("%d", &temp);
			h[temp] = 1;
		}
		flag = 1;
		for (int i = 0;i < M;i++) {
			if (!h[a[i]] && !h[b[i]]) {
				flag = 0;
				break;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
}