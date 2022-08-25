// 1117 Eddington Number
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, E;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        if (n - i < num[i])
        {
            cout << n - i;
            return 0;
        }
    }
    cout << 0;
}