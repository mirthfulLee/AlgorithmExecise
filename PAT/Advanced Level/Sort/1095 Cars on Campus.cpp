// 去除无法成对的记录
// 按照时间排序
// 模拟
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct record
{
	string plate;
	int t;
	bool in, valid;
};
int getTime(string s) {
	return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 5)) * 60 + stoi(s.substr(6));
}
bool cmpOfName(record a, record b) {
	return a.plate != b.plate ? a.plate < b.plate : a.t < b.t;
}
bool cmpOfTime(record a, record b) {
	return a.t < b.t;
}
bool cmpString(string a, string b) {
	return a.compare(b) < 0;
}
int N, K, t, longestSum, curSum, cnt;
string s, act, cur;
vector<record> rcd;
vector<string> longestCar;

int main() {
	cin >> N >> K;
	rcd.assign(N, { "",0,true, true });
	for (int i = 0;i < N;i++) {
		cin >> rcd[i].plate >> s >> act;
		rcd[i].t = getTime(s);
		rcd[i].in = act == "in";
	}
	sort(rcd.begin(), rcd.end(), cmpOfName);
	int p = 0;
	curSum = 0;
	longestSum = 0;
	cur = rcd[0].plate;
	while (p < N) {
		if (rcd[p].plate != cur) {
			if (curSum > longestSum) {
				longestCar.clear();
				longestSum = curSum;
				longestCar.push_back(cur);
			}
			else if (curSum == longestSum) {
				longestCar.push_back(cur);
			}
			cur = rcd[p].plate;
			curSum = 0;
		}
		if (p + 1 < N && rcd[p].plate == rcd[p + 1].plate && rcd[p].in && !rcd[p + 1].in) {
			curSum += rcd[p + 1].t - rcd[p].t;
			p += 2;
		}
		else {
			rcd[p].valid = false;
			p++;
		}

	}
	if (curSum > longestSum) {
		longestCar.clear();
		longestSum = curSum;
		longestCar.push_back(cur);
	}
	else if (curSum == longestSum) {
		longestCar.push_back(cur);
	}

	sort(rcd.begin(), rcd.end(), cmpOfTime);
	cnt = 0;
	p = 0;
	for (int i = 0;i < K;i++) {
		cin >> s;
		t = getTime(s);
		while (rcd[p].t <= t) {
			if (rcd[p].valid) {
				if (rcd[p].in)
					cnt++;
				else cnt--;
			}
			p++;
		}
		printf("%d\n", cnt);
	}

	sort(longestCar.begin(), longestCar.end(), cmpString);
	for (string s : longestCar) cout << s << ' ';
	printf("%02d:%02d:%02d", longestSum / 3600, (longestSum % 3600) / 60, longestSum % 60);
}