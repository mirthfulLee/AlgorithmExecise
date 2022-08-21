// 1156 Sexy Primes
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
    if (a <= 2)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (isPrime(n) && (isPrime(n + 6) || isPrime(n - 6)))
    {
        printf("Yes\n%d", isPrime(n - 6) ? (n - 6) : (n + 6));
    }
    else
    {
        while (!isPrime(n) || !(isPrime(n + 6) || isPrime(n - 6)))
            n++;
        printf("No\n%d", n);
    }
}