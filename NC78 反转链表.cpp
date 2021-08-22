#define _CRT_SECURE_NO_WARNINGS 1
#include "sysutil.h"
//做法一：反向赋值

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode* pre = NULL;
		ListNode* tmp;
		while (pHead)
		{
			tmp = pHead->next;
			pHead->next = pre;
			pre = pHead;
			pHead = tmp;
		}
		return pre;
	}
};

//做法二：向量反转
#include <vector>
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		vector<ListNode*> iv;
		while (pHead)
		{
			iv.push_back(pHead);
			pHead = pHead->next;
		}
		reverse(iv.begin(), iv.end());
		ListNode* head = iv[0];
		ListNode* cur = head;
		for (int i = 1; i < iv.size(); ++i)
		{
			cur->next = iv[i];
			cur = cur->next;
		}
		cur->next = nullptr;
		return head;

	}
};