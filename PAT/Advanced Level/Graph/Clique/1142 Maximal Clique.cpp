#include<iostream>
#include<vector>
using namespace std;
int Nv, Ne, M, K, temp, p, q, e[220][220];

bool isClique(vector<int> v) {
	for (int a : v)
		for (int b : v)
			if (a != b && !e[a][b]) return false;
	return true;
}

int main() {
	cin >> Nv >> Ne;
	for (int i = 0;i < Ne;i++) {
		scanf("%d %d", &p, &q);
		e[p][q] = 1;
		e[q][p] = 1;
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> K;
		vector<int> clique(K);
		for (int j = 0;j < K;j++) scanf("%d", &clique[j]);

		if (!isClique(clique)) {
			printf("Not a Clique\n");
			continue;
		}

		bool isMaximal = true, addable;
		for (int a = 1;a <= Nv;a++) {
			addable = true;
			for (int b : clique) {
				if (a == b || !e[a][b]) {
					addable = false;
					break;
				}
			}
			if (addable) {
				isMaximal = false;
				break;
			}
		}
		printf("%s\n", isMaximal ? "Yes" : "Not Maximal");
	}
	return 0;
}