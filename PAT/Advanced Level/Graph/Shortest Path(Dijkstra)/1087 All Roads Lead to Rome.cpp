#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct Dis
{
	int cost;
	int happiness;
	int level;
	int cnt;
	int former;

	bool operator<(const Dis& b) {
		if (this->cost != b.cost) return this->cost < b.cost;
		else if (this->happiness != b.happiness) return this->happiness > b.happiness;
		else return this->level < b.level;
	}
};

map<string, int> id;
map<int, string> name;
vector<int> h(205), v(205);
int N, K, e[205][205], temp, p, q, destination;
string source, s, t;
const int INF = 0x3FFFFFFF;
vector<Dis> d(205);

void Dijkstra(int cur) {
	if (cur == destination) return;
	for (int i = 0;i < N;i++) {
		if (e[cur][i]) {
			Dis newD = { d[cur].cost + e[cur][i], d[cur].happiness + h[i],d[cur].level + 1,d[cur].cnt, cur };
			if (newD < d[i]) {
				if (newD.cost == d[i].cost) {
					newD.cnt += d[i].cnt;
				}
				d[i] = newD;
			}
			else if (newD.cost == d[i].cost) {
				d[i].cnt += newD.cnt;
			}
		}
	}
	v[cur] = 1;
	int next = 1;
	while (v[next]) next++;
	for (int i = 0;i < N;i++) {
		if (!v[i] && d[i] < d[next]) next = i;
	}
	Dijkstra(next);
}

void printRoute(int cur) {
	if (d[cur].former != cur) {
		printRoute(d[cur].former);
		cout << "->";
	}
	cout << name[cur];
}

int main() {
	cin >> N >> K >> source;
	id[source] = 0;
	name[0] = source;
	d[0] = { 0, 0, 0, 1, 0 };
	for (int i = 1;i < N;i++) {
		cin >> s >> h[i];
		id[s] = i;
		name[i] = s;
		d[i] = { INF, 0,INF,1 ,i };
	}
	destination = id["ROM"];
	for (int i = 0;i < K;i++) {
		cin >> s >> t >> temp;
		p = id[s]; q = id[t];
		e[p][q] = temp;
		e[q][p] = temp;
	}
	Dijkstra(0);
	cout << d[destination].cnt << ' ' << d[destination].cost << ' ' << d[destination].happiness << ' ' << d[destination].happiness / d[destination].level << endl;
	printRoute(destination);
}