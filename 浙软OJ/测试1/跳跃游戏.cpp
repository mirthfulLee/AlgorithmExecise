#include <iostream>
using namespace std;

int main()
{
	long long l, r, mid, i, n, k, sum;
	cin >> n;
	l = 0;
	r = 1500000000;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (mid % 2)
			sum = (mid + 1) / 2 * mid;
		else
			sum = mid / 2 * (mid + 1);

		if (sum < n)
			l = mid + 1;
		else
			r = mid;
	}
	cout << ((r * (r + 1) / 2) == n + 1 ? r + 1 : r);
}