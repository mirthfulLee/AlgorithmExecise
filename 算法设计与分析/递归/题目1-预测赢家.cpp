#include<iostream>
#include<cmath>
using namespace std;

int a[100], S[100];
// 当前玩家能取得的最大分数
int bestScore(int left, int right) {
	if (left == right) return a[left];
	else if (left > right) return 0;
	int chooseL, chooseR;
	chooseL = a[left] + (S[right] - S[left] - bestScore(left + 1, right));
	chooseR = a[right] + (S[right - 1] - S[left - 1] - bestScore(left, right - 1));
	return max(chooseL, chooseR);
}

// 贪心并不适用 50 100 1 2
int main() {
	int n;
	cin >> n;
	S[0] = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		S[i] = S[i - 1] + a[i];
	}
	int player1 = bestScore(1, n);
	int player2 = S[n] - player1;
	printf("%s\n", player1 > player2 ? "True" : "False");
	return 0;
}