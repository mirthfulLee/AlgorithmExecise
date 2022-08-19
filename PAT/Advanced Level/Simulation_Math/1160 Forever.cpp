// 1160 Forever
// 递归位数，通过各个条件筛选答案
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct solution
{
    int n, A;
    bool operator<(const solution &b)
    {
        return n == b.n ? (A < b.A) : (n < b.n);
    }
};

int caseNum, k, m;
vector<solution> result;

int greatestCommonDivisor(int a, int b)
{
    // 不能作sqrt
    for (int i = b; i > 2; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return 1;
}

int digitSumOf(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
// FIXME： 判断质数的一些细节！
bool is_prime(int a){
    // 1不是质数
    if (a <= 2)
        return false;
    // 注意是<=
    for (int i = 2; i <= sqrt(a);i++){
        if (a %i==0)
            return false;
    }
    return true;
}

void find(int leftDigit, int leftSum, int curNum, int base)
{
    if (leftSum < 1)
        return;
    if (leftSum > 9 * leftDigit)
        return;
    if (leftDigit == 1)
    {
        if (leftSum > 9)
            return;
        curNum = base * leftSum + curNum;
        int n = digitSumOf(curNum + 1);
        int gcd = greatestCommonDivisor(m, n);
        if ( gcd > 2 && is_prime(gcd))
        {
            // printf("%d %d\n", n, curNum);
            solution t = {n, curNum};
            result.push_back(t);
        }
        return;
    }
    for (int d = 0; d < 10; d++)
    {
        find(leftDigit - 1, leftSum - d, curNum + d * base, 10 * base);
    }
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> k >> m;
        printf("Case %d\n", i + 1);
        result.clear();
        find(k, m, 0, 1);
        if (result.empty())
        {
            printf("No Solution\n");
        }
        else
        {
            sort(result.begin(), result.end());
            for (solution t : result)
            {
                printf("%d %d\n", t.n, t.A);
            }
        }
    }
}