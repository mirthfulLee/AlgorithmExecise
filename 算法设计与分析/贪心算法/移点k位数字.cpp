#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int num = 5284316;
	int k = 3;

	cout << "num = " << num << endl;
	cout << "k = " << k << endl;

	string s = to_string(num);

	for (int i = 0;i < k;i++) {
		int t = 0;
		while (t < s.size() && s[t] <= s[t + 1]) {
			t++;
		}
		s.erase(t, 1);
	}

	cout << "最小的数字为：" << s << endl;

	return 0;
}