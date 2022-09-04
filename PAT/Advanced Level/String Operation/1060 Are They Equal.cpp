// 1060 Are They Equal
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int sigD;
string a, b, d1, d2;

string transfer(string s, int sigD)
{
    int p = min(s.find_first_of('.'), s.length()), start = 0, exp;
    string sig;
    while (start < s.length() && (s[start] == '0' || s[start] == '.'))
        start++;
    if (p>start) 
        exp = p - start;
    else
        exp = p - start + 1;

    // 0的输出为0.000*10^0
    if (start == s.length())
        exp = 0;
    int pos = start;
    for (int i = 0; i < sigD; i++, pos++)
    {
        if (s[pos] == '.')
            pos++;
        if (pos >= s.length())
            sig += '0';
        else
            sig += s[pos];
    }
    string result = "0." + sig + "*10^" + to_string(exp);
    return result;
}

int main()
{
    cin >> sigD >> a >> b;
    d1 = transfer(a, sigD);
    d2 = transfer(b, sigD);
    if (d1.compare(d2)==0)
        cout << "YES " << d1;
    else
        cout << "NO " << d1 << ' ' << d2;
    
}