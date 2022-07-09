#include<iostream>
using namespace std;

bool is2ex(int num) {
	if (num == 1) return true;
	else return num % 2 == 0 && is2ex(num / 2);
}

int main() {
	int n;
	cin >> n;
	printf("%s\n", is2ex(n) ? "true" : "false");
}