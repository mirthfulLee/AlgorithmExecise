// LCP 62. 交通枢纽
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int transportationHub(vector<vector<int>>& path) {
  map<int, int> in, out;
  set<int> nodes;
  for (auto &pair : path) {
    nodes.insert(pair[0]);
    nodes.insert(pair[1]);
    out[pair[0]]++;
    in[pair[1]]++;
  }
  int node_num = nodes.size();
  for (auto pair: in) {
    if (pair.second == node_num - 1 && out.find(pair.first) == out.end())
      return pair.first;
  }
  return -1;
}