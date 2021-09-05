// 用map记录访问次数：O（logN）
// 用vector做排名:O(N)
#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct recmd
{
	int v, actime;
};
map<int, int> cnt;
vector<recmd> rec;
int N, query, K;
recmd cur;
int getPosition(int t) {
	for (int i = 0;i < rec.size();i++)
		if (t == rec[i].v) return i;
	return rec.size();
}
bool cmp(recmd a, recmd b) {
	return a.actime != b.actime ? a.actime > b.actime : a.v < b.v;
}
int main() {
	cin >> N >> K;
	scanf("%d", &query);
	cnt[query]++;
	cur = { query, 1 };
	rec.push_back(cur);
	for (int t = 1;t < N;t++) {
		scanf("%d", &query);
		printf("%d:", query);
		for (auto it : rec) printf(" %d", it.v);
		printf("\n");
		cur = { query, ++cnt[query] };
		int p = getPosition(query);
		if (p == rec.size()) {
			if (rec.size() < K) {
				rec.push_back(cur);
			}
			else if (cmp(cur, rec[p - 1])) {
				rec[p - 1] = cur;
				p = p - 1;
			}
			else continue;
		}
		else {
			rec[p].actime++;
		}
		while (p > 0 && cmp(rec[p], rec[p - 1])) {
			cur = rec[p - 1];
			rec[p - 1] = rec[p];
			rec[p] = cur;
			p--;
		}
	}
	return 0;
}