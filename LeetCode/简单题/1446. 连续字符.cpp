#include <iostream>
#include <string>
using namespace std;

int maxPower(string s) {
    int cur = 1, longest = 1;
    for (int i = 1;i < s.length();i++) {
        if (s[i] == s[i-1]) cur++;
        else cur = 1;
        if (longest < cur) longest = cur;
    }
    return longest;
}