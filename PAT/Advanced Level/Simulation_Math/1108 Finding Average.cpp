#include<string>
#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
bool legal;
int N, total_num;
float sum;
string s, inpt;
bool legalNumber(string s) {
	int point, pcnt = 0;
	for (int i = 0;i < s.size();i++) {
		if (!isdigit(s[i])) {
			if (s[i] == '-') {
				if (i != 0) return false;
			}
			else if (s[i] == '.') {
				point = i;
				pcnt++;
			}
			else return false;
		}
	}
	if (pcnt == 0) return stof(s) >= -1000 && stof(s) <= 1000;
	else if (pcnt == 1) {
		if (s.size() - point > 3) return false;
		else return stof(s) >= -1000 && stof(s) <= 1000;
	}
	else return false;
}
int main() {
	cin >> N;
	total_num = 0;
	sum = 0;
	for (int k = 0;k < N;k++) {
		cin >> inpt;
		if (legalNumber(inpt)) {
			total_num++;
			sum += stof(inpt);
		}
		else {
			printf("ERROR: %s is not a legal number\n", inpt.c_str());
		}
	}
	if (total_num == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (total_num == 1)
		printf("The average of 1 number is %.2f\n", sum / total_num);
	else
		printf("The average of %d numbers is %.2f\n", total_num, sum / total_num);
}