#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void printList(ListNode* head) {
	ListNode* cur = head->next;
	printf("%d", head->val);
	while (cur != NULL) {
		printf(" -> %d", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* constructList(int* a, int len) {
	int i = len - 1;
	ListNode* cur = NULL;
	while (i >= 0) {
		cur = new ListNode({ a[i], cur });
		i--;
	}
	return cur;
}
ListNode* merge(ListNode* a, ListNode* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->val < b->val) {
		a->next = merge(a->next, b);
		return a;
	}
	else {
		b->next = merge(a, b->next);
		return b;
	}
}
ListNode* merge(ListNode** lists, int k) {
	if (k == 1) return lists[0];
	ListNode* newLists[10];
	int cnt;
	for (cnt = 0;2 * cnt < k;cnt++) {
		if (2 * cnt + 1 < k)
			newLists[cnt] = merge(lists[2 * cnt], lists[2 * cnt + 1]);
		else newLists[cnt] = lists[2 * cnt];
	}
	return merge(newLists, cnt);
}

int main() {
	const int k = 3;
	//cin >> k;
	int a[5] = { 4,8,9,15,20 };
	int b[3] = { 3,5,7 };
	int c[4] = { 1,6,10,11 };
	ListNode* lists[k] = { constructList(a, 5) ,constructList(b, 3) ,constructList(c, 4) };
	printList(merge(lists, k));
}