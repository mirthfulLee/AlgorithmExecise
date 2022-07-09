#include <iostream>
#include <vector>
using namespace std;

bool is_mirror_decimal(long long a)
{
	vector<int> s(50);
	int len = 0;
	while (a > 0)
	{
		s[len++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

long long get_decimal(vector<int> v, int len, int k)
{
	long long sum = 0, exp = 1;
	for (int i = 0; i < (len - 1) / 2 + 1; i++)
	{
		sum += exp * v[i];
		exp *= k;
	}
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		sum += exp * v[i];
		exp *= k;
	}
	return sum;
}

int main()
{
	int k, n, len = 1, cur_p = 0, cnt = 0;
	long long t, total_sum = 0;
	vector<int> v(50);
	cin >> k >> n;

	v[0] = 1;
	while (cnt < n)
	{
		t = get_decimal(v, len, k);
		if (is_mirror_decimal(t))
		{
			total_sum += t;
			cnt++;
		}

		v[cur_p]++;
		while (v[cur_p] == k)
		{
			v[cur_p] = 0;
			cur_p--;
			if (cur_p < 0)
			{
				len++;
				v.assign(len, 0);
				v[0] = 1;
				cur_p = (len - 1) / 2;
			}
			else
			{
				v[cur_p]++;
				if (v[cur_p] < k)
					cur_p = (len - 1) / 2;
			}
		}
	}
	cout << total_sum;
	return 0;
}