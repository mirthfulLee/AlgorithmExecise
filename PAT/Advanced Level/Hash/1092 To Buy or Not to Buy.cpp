#include<iostream>
#include<string>
using namespace std;

string selling, needing;
int a[128], b[128], extra, missing;

int main() {
	cin >> selling >> needing;
	for (char c : selling) {
		a[c]++;
	}
	for (char c : needing) {
		b[c]++;
	}
	for (int i = 0;i < 128;i++) {
		if (a[i] > b[i]) extra += a[i] - b[i];
		else missing += b[i] - a[i];
	}
	if (missing > 0) printf("No %d", missing);
	else printf("Yes %d", extra);
	return 0;
}