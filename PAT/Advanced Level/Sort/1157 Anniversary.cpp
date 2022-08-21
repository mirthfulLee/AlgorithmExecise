// 1157 Anniversary
// 字符串，1.求交集，2.比较子串

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, p, q, num, oldestGuest = -1, oldestAluCome = -1;
vector<string> alumni(100010), guests(100010);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> alumni[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> guests[i];
    sort(alumni.begin(), alumni.begin() + N);
    sort(guests.begin(), guests.begin() + M);
    p = 0;
    q = 0;
    num = 0;
    while (p < N && q < M)
    {
        if (alumni[p] == guests[q])
        {
            if (oldestAluCome == -1 || alumni[p].substr(6, 8) < alumni[oldestAluCome].substr(6, 8))
            {
                oldestAluCome = p;
            }
            num++;
            p++;
            q++;
        }
        else if (alumni[p] < guests[q])
            p++;
        else
            q++;
    }
    if (num > 0)
    {
        cout << num << endl
             << alumni[oldestAluCome];
    }
    else
    {
        oldestGuest = 0;
        q = 1;
        while (q < M)
        {
            if (guests[q].substr(6, 8) < guests[oldestGuest].substr(6, 8))
                oldestGuest = q;
            q++;
        }
        cout << 0 << endl
             << guests[oldestGuest];
    }
}
