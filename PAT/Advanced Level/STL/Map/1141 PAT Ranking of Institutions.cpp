#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

struct info
{
	string name;
	int rank, num;
	double tws;
};

map<string, int> schoolid;
int N, t;
double temp;
string id, school;
vector<info> cnt;
bool cmp(info a, info b) {
	if (a.tws != b.tws)
		return a.tws > b.tws;
	else if (a.num != b.num)
		return a.num < b.num;
	else return a.name < b.name;
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> id >> temp >> school;
		for (int j = 0;j < school.size();j++) school[j] = tolower(school[j]);
		if (schoolid.find(school) == schoolid.end()) {
			schoolid[school] = cnt.size();
			cnt.push_back({ school, 0, 0, 0.0 });
		}
		t = schoolid[school];
		cnt[t].num++;
		switch (id[0])
		{
		case 'B':
			cnt[t].tws += temp / 1.5;
			break;
		case 'A':
			cnt[t].tws += temp;
			break;
		case 'T':
			cnt[t].tws += temp * 1.5;
			break;
		default:
			break;
		}
	}
	// 注：需要在排序前将浮点类型的tws变为整型，否则会出错。
	for (int i = 0;i < cnt.size();i++) {
		cnt[i].tws = (int)cnt[i].tws;
	}
	sort(cnt.begin(), cnt.end(), cmp);
	printf("%d\n", cnt.size());
	for (int i = 0;i < cnt.size();i++) {
		if (i > 0 && cnt[i].tws == cnt[i - 1].tws)
			cnt[i].rank = cnt[i - 1].rank;
		else cnt[i].rank = i + 1;
		printf("%d %s %d %d\n", cnt[i].rank, cnt[i].name.c_str(), (int)cnt[i].tws, cnt[i].num);
	}

}