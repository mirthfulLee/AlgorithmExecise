// 1112 Stucked Keyboard
#include <iostream>
#include <string>
#include <set>
using namespace std;
set<char> repeated, nonRepeated, stucked;
string origin;
int k, l, r;

int main()
{
    cin >> k;
    cin >> origin;
    l = 0;
    r = 0;
    while (l < origin.size())
    {
        while (r < origin.size() && origin[r] == origin[l])
            r++;
        if ((r - l) % k == 0)
            repeated.insert(origin[l]);
        else
            nonRepeated.insert(origin[l]);
        l = r;
    }
    for (char c : origin)
        if (nonRepeated.find(c) == nonRepeated.end() && repeated.find(c) != repeated.end() && stucked.find(c) == stucked.end())
        {
            stucked.insert(c);
            cout << c;
        }
    cout << endl;
    l = 0;
    while (l<origin.size()){
        cout << origin[l];
        l += stucked.find(origin[l]) != stucked.end() ? k : 1;
    }
}