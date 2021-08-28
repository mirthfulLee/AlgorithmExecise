#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int len[505][505], tim[505][505], N, M, sour, dest, onePath, p, q, l, t, D, T;
vector<int> timePre(505), lenPre(505), timePath, lenPath, v(505), dis(505), waste(505);
const int INF = 0x3FFFFFFF;

void getTimePath(int cur) {
	timePath.push_back(cur);
	if (cur != sour) getTimePath(timePre[cur]);
}

void getLenPath(int cur) {
	lenPath.push_back(cur);
	if (cur != sour) getLenPath(lenPre[cur]);
}
int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> p >> q >> onePath >> l >> t;
		if (!onePath) {
			len[q][p] = l;
			tim[q][p] = t;
		}
		len[p][q] = l;
		tim[p][q] = t;
	}
	cin >> sour >> dest;

	fill(v.begin(), v.begin() + N, 0);
	fill(dis.begin(), dis.begin() + N, INF);
	fill(waste.begin(), waste.begin() + N, INF);
	waste[sour] = 0;
	dis[sour] = 0;
	for (int i = 0;i < N;i++) {
		int cur = 0;
		while (v[cur]) cur++;
		for (int j = 0;j < N;j++)
			if (!v[j] && dis[j] < dis[cur]) cur = j;
		if (cur == dest) break;
		v[cur] = 1;
		for (int j = 0;j < N;j++) {
			if (len[cur][j]) {
				int newD = dis[cur] + len[cur][j], newW = waste[cur] + tim[cur][j];
				if (newD < dis[j]) {
					lenPre[j] = cur;
					dis[j] = newD;
					waste[j] = newW;
				}
				else if (newD == dis[j] && newW < waste[j]) {
					lenPre[j] = cur;
					waste[j] = newW;
				}
			}
		}
	}
	getLenPath(dest);
	D = dis[dest];

	fill(v.begin(), v.begin() + N, 0);
	fill(dis.begin(), dis.begin() + N, INF);
	fill(waste.begin(), waste.begin() + N, INF);
	waste[sour] = 0;
	dis[sour] = 0;
	for (int i = 0;i < N;i++) {
		int cur = 0;
		while (v[cur]) cur++;
		for (int j = 0;j < N;j++)
			if (!v[j] && dis[j] < dis[cur]) cur = j;
		if (cur == dest) break;
		v[cur] = 1;
		for (int j = 0;j < N;j++) {
			if (len[cur][j]) {
				int newD = dis[cur] + tim[cur][j], newW = waste[cur] + 1;
				if (newD < dis[j]) {
					timePre[j] = cur;
					dis[j] = newD;
					waste[j] = newW;
				}
				else if (newD == dis[j] && newW < waste[j]) {
					timePre[j] = cur;
					waste[j] = newW;
				}
			}
		}
	}
	getTimePath(dest);
	T = dis[dest];

	printf("Distance = %d", D);
	if (lenPath == timePath) {
		printf("; Time = %d: ", T);
	}
	else {
		printf(": ");
		for (int i = lenPath.size() - 1; i >= 0; i--) {
			printf("%d", lenPath[i]);
			if (i != 0) printf(" -> ");
		}
		printf("\nTime = %d: ", T);
	}
	for (int i = timePath.size() - 1; i >= 0; i--) {
		printf("%d", timePath[i]);
		if (i != 0) printf(" -> ");
	}
	return 0;
}