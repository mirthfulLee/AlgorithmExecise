// 1061 Dating
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
vector<string> day_map = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    string a, b, c, d;
    char dayC, hourC;
    cin >> a >> b >> c >> d;
    int p = 0, hour, day;
    while (!(a[p] == b[p] && a[p] >= 'A' && a[p] <= 'G'))
        p++;
    dayC = a[p];
    p++;
    while (!(a[p] == b[p] && ((a[p] >= '0' && a[p] <= '9') || (a[p] >= 'A' && a[p] <= 'N'))))
        p++;
    hourC = a[p];
    if (hourC <= '9')
        hour = hourC - '0';
    else
        hour = hourC - 'A' + 10;
    p = 0;
    while (!(c[p] == d[p] && (c[p] >= 'a' && c[p] <= 'z') || (c[p] >= 'A' && c[p] <= 'Z')))
        p++;
    cout << day_map[dayC - 'A'];
    printf(" %02d:%02d", hour, p);
}