// 846. 一手顺子
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    map<int, int> cnt;
    for (int i : hand) {
      ++cnt[i];
    }
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
      if (it->second > 0) {
        auto x = it;
        for (int i = 1; i < groupSize; ++i) {
          x++;
          if (x != cnt.end() && x->first - it->first == i &&
              x->second >= it->second) {
            x->second -= it->second;
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main () {
  vector<int> hand = {1,2,3,6,2,3,4,7,8};
  Solution sol;
  sol.isNStraightHand(hand, 3);
}