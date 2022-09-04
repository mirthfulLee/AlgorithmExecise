// 1059 Prime Factors
#include <iostream>
#include <map>
using namespace std;

int main()
{
    long long n, num;
    map<long long, long long> comp;
    cin >> n;
    num = n;
    if (n==1)
        comp[1] = 1;
    for (long long i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            comp[i]++;
            num /= i;
        }
    }
    if (num > 1)
        comp[num]++;
    printf("%lld=", n);
    for (auto it = comp.begin(); it != comp.end(); it++)
    {
        if (it != comp.begin())
            printf("*");
        printf("%lld", it->first);
        if (it->second > 1)
            printf("^%lld", it->second);
    }
}