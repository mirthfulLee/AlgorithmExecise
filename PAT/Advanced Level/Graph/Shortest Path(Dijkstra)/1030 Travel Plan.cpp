#include<iostream>
#include<map>
#include<vector>
using namespace std;

int N, M, source, destination, p, q, a, b;
map <int, int> dis[500], cost[500];
vector<int> visted(500), D(500, 0x0FFFFFFF), C(500, 0x0FFFFFFF), r(500);

void printRoute(int cur) {
	if (r[cur] != cur) printRoute(r[cur]);
	cout << cur << ' ';
}

void Dijkstra(int cur) {
	if (cur == destination) return;

	for (auto it = dis[cur].begin(); it != dis[cur].end();it++) {
		if (D[cur] + it->second < D[it->first]) {
			D[it->first] = D[cur] + it->second;
			C[it->first] = C[cur] + cost[cur][it->first];
			r[it->first] = cur;
		}
		else if (D[cur] + it->second == D[it->first] && C[it->first] > C[cur] + cost[cur][it->first]) {
			C[it->first] = C[cur] + cost[cur][it->first];
			r[it->first] = cur;
		}
	}

	visted[cur] = 1;
	int next = 0;
	while (visted[next]) next++;
	for (int i = next + 1;i < N;i++) {
		if (!visted[i]) {
			if (D[i] < D[next] || D[i] == D[next] && C[i] < C[next]) {
				next = i;
			}
		}
	}
	Dijkstra(next);
}

int main() {
	cin >> N >> M >> source >> destination;
	for (int i = 0;i < M;i++) {
		cin >> p >> q >> a >> b;
		dis[p][q] = a; dis[q][p] = a;
		cost[p][q] = b;cost[q][p] = b;
	}
	D[source] = 0;
	C[source] = 0;
	r[source] = source;
	Dijkstra(source);
	printRoute(destination);
	cout << D[destination] << ' ' << C[destination];
}