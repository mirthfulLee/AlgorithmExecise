#include<vector>
#include<iostream>

using namespace std;

int N, M, K, isTSCycle, legal, isSimple, p, q, temp, pathsize, shortest, label, total;
int e[250][250];
int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		scanf("%d %d %d", &p, &q, &temp);
		e[p][q] = temp; e[q][p] = temp;
	}
	cin >> K;
	shortest = 0x3fffffff;
	for (int i = 1;i <= K;i++) {
		cin >> pathsize;
		legal = 1;
		total = 0;
		vector<int> path(pathsize), v(N + 1);
		cin >> path[0];
		for (int j = 1;j < pathsize;j++) {
			cin >> path[j];
			if (!e[path[j - 1]][path[j]]) legal = 0;
			total += e[path[j - 1]][path[j]];
			v[path[j]] = 1;
		}
		if (!legal) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
		}
		else {
			printf("Path %d: %d ", i, total);

			isTSCycle = 1;
			for (int j = 1;j <= N;j++) isTSCycle = isTSCycle & v[j];
			if (!isTSCycle) {
				printf("%s", "(Not a TS cycle)\n");
			}
			else if (pathsize == N + 1) {
				printf("%s", "(TS simple cycle)\n");
			}
			else {
				printf("%s", "(TS cycle)\n");
			}
			if (isTSCycle && total < shortest) {
				shortest = total;
				label = i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d", label, shortest);
}