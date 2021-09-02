#include<iostream>
#include<string>
using namespace std;

int main() {
	int N, a, b, t, l;
	bool flag;
	string input;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> input;
		l = input.size();
		t = stoi(input);
		a = stoi(input.substr(0, l / 2));
		b = stoi(input.substr(l / 2));
		// a, b 可能为0， 导致浮点错误
		// 作除法运算时要注意！
		if (a == 0 || b == 0) flag = false;
		else flag = t % (a * b) == 0;
		cout << (flag ? "Yes" : "No") << endl;
	}
}