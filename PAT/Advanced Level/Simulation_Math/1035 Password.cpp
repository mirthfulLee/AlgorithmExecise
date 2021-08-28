#include<string>
#include<iostream>
using namespace std;

struct team
{
	string username;
	string pswd;
	int modified = 0;
};

int main() {
	int N, cnt = 0;
	cin >> N;
	team t[1010];
	for (int i = 0;i < N;i++) {
		cin >> t[i].username;
		cin >> t[i].pswd;
		for (int j = 0;j < t[i].pswd.size();j++) {
			if (t[i].pswd[j] == '1') { t[i].pswd[j] = '@'; t[i].modified = 1; }
			if (t[i].pswd[j] == '0') { t[i].pswd[j] = '%'; t[i].modified = 1; }
			if (t[i].pswd[j] == 'l') { t[i].pswd[j] = 'L'; t[i].modified = 1; }
			if (t[i].pswd[j] == 'O') { t[i].pswd[j] = 'o'; t[i].modified = 1; }
		}
		if (t[i].modified) cnt++;
	}
	if (N == 1) {
		printf("There is 1 account and no account is modified");
		return 0;
	}
	if (cnt) {
		printf("%d\n", cnt);
		for (int i = 0;i < N;i++) {
			if (t[i].modified) cout << t[i].username << ' ' << t[i].pswd << endl;
		}
	}
	else printf("There are %d accounts and no account is modified", N);
	return 0;
}