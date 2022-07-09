#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int partition(vector<int>& nums, int l, int r)
{
	int pivot = nums[l];
	int i = l + 1, j = r;
	while (true)
	{
		while (i <= j && nums[i] <= pivot) i++;
		while (i <= j && nums[j] >= pivot) j--;
		if (i > j) break;
		swap(nums[i], nums[j]);
	}

	swap(nums[j], nums[l]);
	return j;
}

void quickSort(vector<int>& nums, int l, int r) {
	if (l < r)
	{
		int mid = partition(nums, l, r);
		quickSort(nums, l, mid - 1);
		quickSort(nums, mid + 1, r);
	}
}


vector<int> A = { 4,6,12,10,6,7,9,4,11,5,3,1,8,2 };
int p = 2;
int result = 0;
int longest = 0;
int startIndex = -1;

int lps(int i, int j) {
	int longestPerfectSequence = 0;
	if (A[j] <= A[i] * p) {
		longestPerfectSequence = j - i + 1;
	}
	else {
		longestPerfectSequence = max(lps(i + 1, j), lps(i, j - 1));
	}
	if (longestPerfectSequence > longest) {
		longest = longestPerfectSequence;
		startIndex = i;
	}
	return longestPerfectSequence;
}

int main() {
	cout << "原始数列为：";
	for (int temp : A) {
		cout << " " << temp;
	}
	cout << endl;
	cout << "p=" << p;
	cout << endl;


	quickSort(A, 0, A.size() - 1);
	cout << "排序之后为：";
	for (int temp : A) {
		cout << " " << temp;
	}
	cout << endl;

	result = lps(0, A.size() - 1);

	cout << "最长完美子数列的长度为：" << result;
	cout << endl;
	cout << "最长完美子数列为：";

	for (int i = 0;i < result;i++) {
		cout << " " << A[startIndex + i];
	}
	cout << endl;

	return 0;
}