// 1116 Come on! Let's C
#include <iostream>
#include <vector>
using namespace std;

vector<int> award(10010);
int n, m, p, q, t;
bool isPrime(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    // 0-nothing; 1-Myst; 2-Minion; 3- Choc; -1:checked
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (i == 1)
            award[p] = 1;
        else if (isPrime(i))
            award[p] = 2;
        else
            award[p] = 3;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        if (award[p] == 0)
        {
            printf("%04d: Are you kidding?\n", p);
            continue;
        }
        if (award[p] == 1)
            printf("%04d: Mystery Award\n", p);
        if (award[p] == 2)
            printf("%04d: Minion\n", p);
        if (award[p] == 3)
            printf("%04d: Chocolate\n", p);
        if (award[p] == -1)
            printf("%04d: Checked\n", p);
        award[p] = -1;
    }
}