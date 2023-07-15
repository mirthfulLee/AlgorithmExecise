// 838. 推多米诺
#include<iostream>
#include<string>
#include<map>
using namespace std;
void change(string &s, char target, int i, int j) {
  for (int k=i; k<=j;k++) {
    s[k] = target;
  }
}

string pushDominoes(string dominoes) {
  map<int, char> mark;
  for (int i=0;i<dominoes.length(); i++) {
    if (dominoes[i] != '.'){
      mark[i] = dominoes[i];
    }
  }
  auto p = mark.begin(), q = mark.begin();
  if (q == mark.end()){
    return dominoes;
  }
  q++;
  if (p->second == 'L') {
    change(dominoes, 'L', 0, p->first);
  }
  while (q != mark.end()) {
    if (p->second == 'L' && q->second == 'L') {
      change(dominoes, 'L', p->first, q->first);
    }
    if (p->second == 'R' && q->second == 'L') {
      change(dominoes, 'R', p->first, (p->first + q->first-1)/2);
      change(dominoes, 'L', (p->first + q->first)/2+1, q->first);
    }
    if (p->second == 'R' && q->second == 'R') {
      change(dominoes, 'R', p->first, q->first);
    }
    p++;
    q++;
  }
  if (p->second == 'R') {
    change(dominoes, 'R', p->first, dominoes.length() - 1);
  }
  return dominoes;
}

int main() {
  pushDominoes(".");
}