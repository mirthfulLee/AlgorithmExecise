// 1071 Speech Patterns
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isAlpha(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    string sentence, pattern;
    int freq= 0;
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); i++)
        if (sentence[i] >= 'A' && sentence[i] <= 'Z')
            sentence[i] += 'a' - 'A';
    map<string, int> cnt;
    int l = 0, r;
    while (l < sentence.length())
    {
        r = l;
        while (r < sentence.length() && isAlpha(sentence[r]))
            r++;
        if (r - l)
            cnt[sentence.substr(l, r - l)]++;
        l = r + 1;
    }
    for (auto it = cnt.begin(); it != cnt.end();it++){
        if (it->second > freq){
            pattern = it->first;
            freq = it->second;
        }
    }
    cout << pattern << ' ' << freq;
}