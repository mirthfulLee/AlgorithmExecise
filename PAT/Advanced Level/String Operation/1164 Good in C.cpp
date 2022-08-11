// 1164 Good in C
#include <iostream>
#include <string>
using namespace std;

string figure[26][7];
string in, cur, word;

bool isCaptal(char c)
{
    return c >= 'A' && c <= 'Z';
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> figure[i][j];
        }
    }
    // 句子中的分隔符可能为空格;
    // cin 会保留缓冲区的换行符\n，所以要用cin.ignore 或者 getchar()把换行符先移出缓冲区再读取整行
    // cin >> in;
    cin.ignore(1, '\n');
    getline(cin, in);
    int l = 0, p, r;
    while (!isCaptal(in[l]))
        l++;
    p = l;
    while (p < in.length())
    {
        while (p < in.length() && isCaptal(in[p]))
            p++;
        r = p - 1;
        // print word between in[l, r]
        for (int i = 0; i < 7; i++)
        {
            for (int j = l; j < r; j++)
            {
                cout << figure[in[j] - 'A'][i] << ' ';
            }
            cout << figure[in[r] - 'A'][i] << endl;
        }
        while (p < in.length() && !isCaptal(in[p]))
            p++;
        if (p < in.length())
            cout << endl;
        l = p;
    }
    return 0;
}