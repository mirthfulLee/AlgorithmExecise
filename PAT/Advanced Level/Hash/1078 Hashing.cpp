// 1078 Hashing
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int Msize, n, Tsize, num, h, step;
    cin >> Msize >> n;
    Tsize = Msize;
    while (!isPrime(Tsize))
        Tsize++;
    vector<int> hashTable(Tsize);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        // FIXME: 探针最多可以尝试n次
        for (step = 0; step < n; step++)
        {
            h = (num + step * step) % Tsize;
            if (hashTable[h] == 0)
            {
                hashTable[h] = num;
                if (i)
                    cout << ' ';
                cout << h;
                break;
            }
        }
        if (step == n)
        {
            if (i)
                cout << ' ';
            cout << '-';
        }
    }
}