#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

struct record
{
	string id;
	int p, mid, final, g;
};
vector<record> arr;
map<string, int> order;
int N, M, K, temp, num = 0;
string id, s;
int getId(string s) {
	auto it = order.find(s);
	if (it != order.end()) return it->second;
	order[s] = num;
	// 用-1区分数不存在和分数为0
	arr.push_back({ s, 0,-1,-1,0 });
	return num++;
}
bool cmp(record a, record b) {
	return a.g != b.g ? a.g > b.g:a.id < b.id;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		cin >> s >> temp;
		arr[getId(s)].p = temp;
	}
	for (int i = 0;i < M;i++) {
		cin >> s >> temp;
		arr[getId(s)].mid = temp;
	}
	for (int i = 0;i < K;i++) {
		cin >> s >> temp;
		arr[getId(s)].final = temp;
	}
	for (int i = 0;i < num;i++) {
		// 需要注意四舍五入:(a+0.5)来实现
		if (arr[i].mid > arr[i].final)
			arr[i].g = (int)(0.4 * arr[i].mid + 0.6 * arr[i].final + 0.5);
		else arr[i].g = arr[i].final;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0;i < num;i++) {
		if (arr[i].p >= 200 && arr[i].g >= 60) {
			printf("%s %d %d %d %d\n", arr[i].id.c_str(), arr[i].p, arr[i].mid, arr[i].final, arr[i].g);
		}
	}
	return 0;
}