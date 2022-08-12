// 1058 A+B in Hogwarts
#include<iostream>
using namespace std;

int g1, g2, s1, s2, k1, k2, g, s, k;

int main(){
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    k = k1 + k2;
    s = s1 + s2 + k / 29;
    k %= 29;
    g = g1 + g2 + s / 17;
    s %= 17;
    printf("%d.%d.%d\n", g, s, k);
}