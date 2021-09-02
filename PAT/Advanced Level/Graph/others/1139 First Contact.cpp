#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
struct contact
{
	int first, second;
};
int num, N, M, K, temp, adj[400][400], a, b;
map<int, int> id, name, gender;
vector<contact> ans;
string p, q;

bool cmp(contact a, contact b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int getId(string s) {
	int a = stoi(s);
	auto it = id.find(a);
	if (it != id.end()) return it->second;
	id[a] = num;
	if (s.size() == 5) gender[num] = 1;
	else gender[num] = 0;
	name[num] = a;
	return num++;
}
bool sameGender(int a, int b) {
	return gender[a] == gender[b];
}
int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		//如果用int接收， -0000和0000对于int来说都是0，将⽆无法得知这个⼈人的性别
		cin >> p >> q;
		a = getId(p);
		b = getId(q);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	cin >> K;
	for (int i = 0;i < K;i++) {
		cin >> p >> q;
		ans.clear();
		a = getId(p); b = getId(q);
		// A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当当前朋友就是B或者B的同性朋友就是A时舍弃该结果
		for (int j = 0;j < num;j++) {
			if (adj[a][j] && sameGender(a, j) && j != b) {
				for (int t = 0;t < num;t++) {
					if (adj[j][t] && adj[t][b] && sameGender(t, b) && t != a) {
						contact pair = { abs(name[j]), abs(name[t]) };
						ans.push_back(pair);
					}
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (int j = 0;j < ans.size();j++) {
			// 输出时候要以4位数的⽅方式输出，所以要%04d
			printf("%04d %04d\n", ans[j].first, ans[j].second);
		}
	}
}