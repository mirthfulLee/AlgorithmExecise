#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node
{
	int add, dat, nex;
};
map<int, node> memory;
vector<node> negtive, in, gre;
int start, K, N, cur;
void printNode(vector<node>& v, int start) {
	for (int i = start;i < v.size();i++)
		printf(" %05d\n%05d %d", v[i].add, v[i].add, v[i].dat);
}
int main() {
	scanf("%d %d %d", &start, &N, &K);
	for (int i = 0;i < N;i++) {
		node* p = new node();
		scanf("%d %d %d", &(p->add), &(p->dat), &(p->nex));
		memory[p->add] = *p;
	}
	cur = start;
	while (cur != -1) {
		node curNode = memory[cur];
		if (curNode.dat < 0)
			negtive.push_back(curNode);
		else if (curNode.dat <= K)
			in.push_back(curNode);
		else
			gre.push_back(curNode);
		cur = curNode.nex;
	}
	if (negtive.size()) {
		printf("%05d %d", negtive[0].add, negtive[0].dat);
		printNode(negtive, 1);
		printNode(in, 0);
		printNode(gre, 0);
	}
	else if (in.size()) {
		printf("%05d %d", in[0].add, in[0].dat);
		printNode(in, 1);
		printNode(gre, 0);
	}
	else {
		printf("%05d %d", gre[0].add, gre[0].dat);
		printNode(gre, 1);
	}

	printf(" -1");
	return 0;
}
