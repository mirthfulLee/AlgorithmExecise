#include<string.h>
#include<iostream>
#include<map>
using namespace std;

char input[30], output[30];
int cnt[10], flag = 0, len, temp, v;

int main() {
	cin >> input;
	len = strlen(input);
	for (int i = len - 1; i >= 0; i--) {
		v = input[i] - '0';
		cnt[v]++;
		temp = v * 2 + flag;
		cnt[temp % 10]--;
		output[i] = temp % 10 + '0';
		flag = temp / 10;
	}
	if (flag) {
		printf("No\n");
		printf("1%s", output);
		return 0;
	}

	flag = 1;
	for (int i = 0;i < 10;i++) {
		if (cnt[i] != 0) flag = 0;
	}
	if (flag)printf("Yes\n");
	else printf("No\n");
	printf("%s", output);
	return 0;
}