// 1032 Sharing
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> next(100000);
    vector<bool> included(100000, false);
    char ch;
    int sa, sb, n, add, p, result;
    cin >> sa >> sb >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> ch >> p;
        next[add] = p;
    }
    p = sa;
    while (p != -1)
    {
        included[p] = true;
        p = next[p];
    }
    p = sb;
    while (p != -1)
    {
        if (included[p])
            break;
        p = next[p];
    }
    if (p < 0)
        cout << p;
    else
        printf("%05d", p);
}