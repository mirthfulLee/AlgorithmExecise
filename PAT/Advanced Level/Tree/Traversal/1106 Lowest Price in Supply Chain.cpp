//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/1.
//
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct Node
{
	int level;
	vector<int> kids;
};

int N, K, t, lo, num;
double P, r;
Node node[100020];
queue<int> q;

void bfs() {
	int cur;
	while (q.size()) {
		cur = q.front(); q.pop();
		if (node[cur].kids.size() == 0) {
			lo = node[cur].level;
			num = 1;
			while (q.size()) {
				if (node[q.front()].level == lo && node[q.front()].kids.size() == 0) {
					num++;
				}
				q.pop();
			}
			return;
		}
		for (int i = 0;i < node[cur].kids.size();i++) {
			node[node[cur].kids[i]].level = node[cur].level + 1;
			q.push(node[cur].kids[i]);
		}
	}
}

int main() {
	cin >> N >> P >> r;
	r = (100 + r) / 100;
	for (int i = 0;i < N;i++) {
		cin >> K;
		for (int j = 0;j < K;j++) {
			cin >> t;
			node[i].kids.push_back(t);
		}
	}
	node[0].level = 0;
	q.push(0);
	bfs();
	printf("%.4f %d", P * pow(r, lo), num);
}