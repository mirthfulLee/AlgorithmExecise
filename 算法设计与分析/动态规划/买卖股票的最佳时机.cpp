#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> prices = { 7,1,5,3,6,4 };
	int profit = 0;
	for (int i = 1;i < prices.size();i++) {
		int dev = prices[i] - prices[i - 1];
		if (dev > 0) profit += dev;
	}
	cout << profit;
}