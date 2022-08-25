// 1100 Mars Numbers
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> l = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> h = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
    int n, p;
    string s;
    cin >> n;
    getchar();
    for (int k = 0; k < n; k++)
    {
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9')
        {
            p = stoi(s);
            if (p / 13)
                cout << h[p / 13];
            if (p / 13 && p % 13)
                cout << ' ';
            if (p % 13 || p==0)
                cout << l[p % 13];
            cout << endl;
        }
        else
        {
            int result = 0, x = 0, y = 0;
            string a = s.substr(0, 3), b;
            if (s.size() > 4)
                b = s.substr(4, 3);
            for (int i = 0; i < 13; i++)
            {
                if (a == h[i])
                    x = i;
                if (b == l[i] || a == l[i])
                    y = i;
            }
            cout << 13 * x + y << endl;
        }
    }
}