#include <stdio.h>
#include <stdlib.h>

////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(使用额外数组的方法)
//void rotate(int* nums, int numsSize, int k)
//{
//	int* tmp = (int*)malloc(sizeof(int) * numsSize);
//	for (int i = 0; i < numsSize; ++i)
//	{
//		tmp[i] = nums[i];
//	}
//	for (int i = 0; i < numsSize; ++i)
//	{
//		nums[(i + k) % numsSize] = tmp[i];
//	}
//	free(tmp);
//}

////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(三步翻转法)
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void Reverse(int* nums, int x, int y)
//{
//	while (x < y)
//	{
//		Swap(&nums[x++], &nums[y--]);
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	Reverse(nums, 0, numsSize - 1);
//	Reverse(nums, k, numsSize - 1);
//	Reverse(nums, 0, k - 1);
//}

////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(环状替换法)
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	for (int start = 0, count = 0; start < numsSize && count < numsSize; ++start)
//	{
//		int cur = start;
//		do
//		{
//			int next = (cur + k) % numsSize;
//			Swap(&nums[start], &nums[next]);
//			cur = next;
//			++count;
//		} while (start != cur);
//	}
//}

////消失的数字：https://leetcode-cn.com/problems/missing-number-lcci/。(方法一)
//int missingNumber(int* nums, int numsSize)
//{
//	int total = numsSize * (numsSize + 1) / 2;
//	int sum = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		sum += nums[i];
//	}
//	return total - sum;
//}

////消失的数字：https://leetcode-cn.com/problems/missing-number-lcci/。(方法二)
//int missingNumber(int* nums, int numsSize)
//{
//	int xor = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		xor ^= i;
//		xor ^= nums[i];
//	}
//	return (xor ^= numsSize);
//}

////移除元素：https://leetcode.cn/problems/remove-element/。
//int removeElement(int* nums, int numsSize, int val)
//{
//	int j = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		if (nums[i] != val)
//		{
//			nums[j++] = nums[i];
//		}
//	}
//	return j;
//}

////删除有序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/。
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize < 2)
//	{
//		return numsSize;
//	}
//	int j = 0;
//	for (int i = 1; i < numsSize; ++i)
//	{
//		if (nums[i] != nums[j])
//		{
//			nums[++j] = nums[i];
//		}
//	}
//	return ++j;
//}

////合并两个有序数组：https://leetcode.cn/problems/merge-sorted-array/。
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int x = m + n - 1;
//	while (n)
//	{
//		if (m == 0 || nums1[m - 1] <= nums2[n - 1])
//		{
//			nums1[x--] = nums2[--n];
//		}
//		else
//		{
//			nums1[x--] = nums1[--m];
//		}
//	}
//}

////移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/。(常规方法)
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* prev = NULL, * cur = head;
//	while (cur != NULL)
//	{
//		if (cur->val == val)
//		{
//			if (prev == NULL)
//			{
//				head = head->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

////移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/。(重建链表方法(步步置空))
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* newhead = NULL;
//	struct ListNode* newheadCur = NULL;
//	struct ListNode* headCur = head;
//	while (headCur != NULL)
//	{
//		if (headCur->val != val)
//		{
//			if (newhead == NULL)
//			{
//				newheadCur = newhead = headCur;
//				headCur = headCur->next;
//				newhead->next = NULL;
//			}
//			else
//			{
//				newheadCur->next = headCur;
//				headCur = headCur->next;
//				newheadCur = newheadCur->next;
//				newheadCur->next = NULL;
//			}
//		}
//		else
//		{
//			struct ListNode* del = headCur;
//			headCur = headCur->next;
//			free(del);
//		}
//	}
//	return newhead;
//}

////移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/。(重建链表方法(最后置空))
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* newhead = NULL;
//	struct ListNode* newheadCur = NULL;
//	struct ListNode* headCur = head;
//	while (headCur != NULL)
//	{
//		if (headCur->val != val)
//		{
//			if (newhead == NULL)
//			{
//				newheadCur = newhead = headCur;
//			}
//			else
//			{
//				newheadCur->next = headCur;
//				newheadCur = newheadCur->next;
//			}
//			headCur = headCur->next;
//		}
//		else
//		{
//			struct ListNode* del = headCur;
//			headCur = headCur->next;
//			free(del);
//		}
//	}
//	if (newheadCur != NULL)
//		newheadCur->next = NULL;
//	return newhead;
//}

////移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/。(创建哨兵位节点方法)
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
//	guard->next = head;
//	struct ListNode* cur = guard;
//	while (cur->next != NULL)
//	{
//		if (cur->next->val == val)
//		{
//			struct ListNode* next = cur->next->next;
//			free(cur->next);
//			cur->next = next;
//		}
//		else
//		{
//			cur = cur->next;
//		}
//	}
//	return guard->next;
//}

////反转链表：https://leetcode.cn/problems/reverse-linked-list/。(重建链表方法)
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* newhead = NULL;
//	struct ListNode* headCur = head;
//	while (headCur != NULL)
//	{
//		struct ListNode* next = headCur->next;
//		headCur->next = newhead;
//		newhead = headCur;
//		headCur = next;
//	}
//	return newhead;
//}

////反转链表：https://leetcode.cn/problems/reverse-linked-list/。(三指针方法(包含头指针))
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* prev = NULL;
//	struct ListNode* next = NULL;
//	while (head != NULL)
//	{
//		next = head->next;
//		head->next = prev;
//		prev = head;
//		head = next;
//	}
//	return prev;
//}

////链表的中间结点：https://leetcode.cn/problems/middle-of-the-linked-list/。
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* fast, * slow;
//	fast = slow = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}

////链表中倒数第k个节点：https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/。
//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//	struct ListNode* fast, * slow;
//	fast = slow = head;
//	while (k-- && fast)
//	{
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}

////合并两个有序链表：https://leetcode.cn/problems/merge-two-sorted-lists/submissions/。
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	if (list1 == NULL || list2 == NULL)
//		return list1 == NULL ? list2 : list1;
//	struct ListNode* head = list1->val <= list2->val ? list1 : list2;
//	struct ListNode* cur1 = head->next;
//	struct ListNode* cur2 = head == list1 ? list2 : list1;
//	struct ListNode* prev = head;
//	while (cur1 && cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			prev->next = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			prev->next = cur2;
//			cur2 = cur2->next;
//		}
//		prev = prev->next;
//	}
//	prev->next = cur1 != NULL ? cur1 : cur2;
//	return head;
//}

////分隔链表：https://leetcode.cn/problems/partition-list/。
//struct ListNode* partition(struct ListNode* head, int x)
//{
//	if (head == NULL)
//		return NULL;
//	struct ListNode* lessGuard, * lessTail, * greaterGuard, * greaterTail;
//	lessTail = lessGuard = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterTail = greaterGuard = (struct ListNode*)malloc(sizeof(struct ListNode));
//	lessGuard->next = greaterGuard->next = NULL;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = lessTail->next;
//		}
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = greaterTail->next;
//		}
//		cur = cur->next;
//	}
//	lessTail->next = greaterGuard->next;
//	greaterTail->next = NULL;
//	head = lessGuard->next;
//	free(lessGuard);
//	free(greaterGuard);
//	return head;
//}

////回文链表：https://leetcode.cn/problems/palindrome-linked-list/。
//bool isPalindrome(struct ListNode* head)
//{
//	struct ListNode* n1, * n2;
//	n2 = n1 = head;
//	while (n2->next && n2->next->next)
//	{
//		n1 = n1->next;
//		n2 = n2->next->next;
//	}
//	n2 = n1->next;
//	n1->next = NULL;
//	struct ListNode* n3 = NULL;
//	while (n2)
//	{
//		n3 = n2->next;
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//	}
//	n3 = n1;
//	n2 = head;
//	bool res = true;
//	while (n1 && n2)
//	{
//		if (n1->val != n2->val)
//		{
//			res = false;
//			break;
//		}
//		n1 = n1->next;
//		n2 = n2->next;
//	}
//	n1 = n3->next;
//	n3->next = NULL;
//	while (n1)
//	{
//		n2 = n1->next;
//		n1->next = n3;
//		n3 = n1;
//		n1 = n2;
//	}
//	return res;
//}

////相交链表：https://leetcode.cn/problems/intersection-of-two-linked-lists/。
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//	if (headA == NULL && headB == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* cur1 = headA;
//	struct ListNode* cur2 = headB;
//	int n = 0;
//	while (cur1->next != NULL)
//	{
//		++n;
//		cur1 = cur1->next;
//	}
//	while (cur2->next != NULL)
//	{
//		--n;
//		cur2 = cur2->next;
//	}
//	if (cur1 != cur2)
//	{
//		return NULL;
//	}
//	cur1 = n > 0 ? headA : headB;
//	cur2 = cur1 == headA ? headB : headA;
//	n = abs(n);
//	while (n--)
//	{
//		cur1 = cur1->next;
//	}
//	while (cur1 != cur2)
//	{
//		cur1 = cur1->next;
//		cur2 = cur2->next;
//	}
//	return cur1;
//}

////环形链表：https://leetcode.cn/problems/linked-list-cycle/。
//bool hasCycle(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL || head->next->next == NULL)
//	{
//		return false;
//	}
//	struct ListNode* slow = head->next;
//	struct ListNode* fast = head->next->next;
//	while (slow != fast)
//	{
//		if (fast->next == NULL || fast->next->next == NULL)
//		{
//			return false;
//		}
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return true;
//}

////环形链表 II：https://leetcode.cn/problems/linked-list-cycle-ii/。
//struct ListNode* detectCycle(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL || head->next->next == NULL)
//	{
//		return false;
//	}
//	struct ListNode* slow = head->next;
//	struct ListNode* fast = head->next->next;
//	while (slow != fast)
//	{
//		if (fast->next == NULL || fast->next->next == NULL)
//		{
//			return false;
//		}
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	fast = head;
//	while (slow != fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}

////复制带随机指针的链表：https://leetcode.cn/problems/copy-list-with-random-pointer/submissions/。("while"循环版本)
//struct Node* copyRandomList(struct Node* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct Node* cur = head;
//	while (cur != NULL)
//	{
//		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//		newNode->val = cur->val;
//		newNode->next = cur->next;
//		cur->next = newNode;
//		cur = cur->next->next;
//	}
//	cur = head;
//	struct Node* curNewNode, * next;
//	while (cur != NULL)
//	{
//		next = cur->next->next;
//		curNewNode = cur->next;
//		curNewNode->random = cur->random == NULL ? NULL : cur->random->next;
//		cur = next;
//	}
//	cur = head;
//	struct Node* newHead = head->next;
//	while (cur != NULL)
//	{
//		next = cur->next->next;
//		curNewNode = cur->next;
//		cur->next = next;
//		curNewNode->next = curNewNode->next == NULL ? NULL : curNewNode->next->next;
//		cur = cur->next;
//	}
//	return newHead;
//}

////复制带随机指针的链表：https://leetcode.cn/problems/copy-list-with-random-pointer/submissions/。("for"循环版本)
//struct Node* copyRandomList(struct Node* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	for (struct Node* cur = head; cur != NULL; cur = cur->next->next)
//	{
//		struct Node* curNewNode = (struct Node*)malloc(sizeof(struct Node));
//		curNewNode->val = cur->val;
//		curNewNode->next = cur->next;
//		cur->next = curNewNode;
//	}
//	for (struct Node* cur = head; cur != NULL; cur = cur->next->next)
//	{
//		struct Node* curNewNode = cur->next;
//		curNewNode->random = (cur->random != NULL) ? cur->random->next : NULL;
//	}
//	struct Node* res = head->next;
//	for (struct Node* cur = head; cur != NULL; cur = cur->next)
//	{
//		struct Node* curNewNode = cur->next;
//		cur->next = cur->next->next;
//		curNewNode->next = (curNewNode->next != NULL) ? curNewNode->next->next : NULL;
//	}
//	return res;
//}

////相交链表：给定两个可能有环也可能无环的单链表，头节点为"head1"和"head2"。请实现一个函数，如果两个链表相交，请返回链表相交的第一个节点，如果不相交，返回"NULL"。
////要求：
////	1. 如果两个链表的长度之和为"N"，时间复杂度请达到"O(N)"，额外空间复杂度请达到"O(1)"。
//typedef int SLLDataType;
//
//typedef struct SinglyLinkedListNode
//{
//	SLLDataType data;
//	struct SinglyLinkedListNode* next;
//} SLLNode;
//
//SLLNode* Create_SinglyLinkedListNode(SLLDataType data)
//{
//	SLLNode* newNode = (SLLNode*)malloc(sizeof(SLLNode));
//	if (newNode == NULL)
//	{
//		perror("Create_SinglyLinkedListNode");
//		exit(EXIT_FAILURE);
//	}
//	newNode->data = data;
//	newNode->next = NULL;
//	return newNode;
//}
//
//SLLNode* GetLoopNode(SLLNode* head)
//{
//	if (head == NULL || head->next == NULL || head->next->next == NULL)
//	{
//		return NULL;
//	}
//	SLLNode* slow = head->next;
//	SLLNode* fast = head->next->next;
//	while (slow != fast)
//	{
//		if (fast->next == NULL || fast->next->next == NULL)
//		{
//			return NULL;
//		}
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	fast = head;
//	while (slow != fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}
//
//SLLNode* NoLoop(SLLNode* head1, SLLNode* head2)
//{
//	if (head1 == NULL || head2 == NULL)
//	{
//		return NULL;
//	}
//	SLLNode* cur1 = head1;
//	SLLNode* cur2 = head2;
//	int n = 0;
//	while (cur1->next != NULL)
//	{
//		++n;
//		cur1 = cur1->next;
//	}
//	while (cur2->next != NULL)
//	{
//		--n;
//		cur2 = cur2->next;
//	}
//	if (cur1 != cur2)
//	{
//		return NULL;
//	}
//	cur1 = n > 0 ? head1 : head2;
//	cur2 = cur1 == head1 ? head2 : head1;
//	n = abs(n);
//	while (n--)
//	{
//		cur1 = cur1->next;
//	}
//	while (cur1 != cur2)
//	{
//		cur1 = cur1->next;
//		cur2 = cur2->next;
//	}
//	return cur1;
//}
//
//SLLNode* BothLoop(SLLNode* head1, SLLNode* loop1, SLLNode* head2, SLLNode* loop2)
//{
//	SLLNode* cur1 = NULL;
//	SLLNode* cur2 = NULL;
//	if (loop1 == loop2)
//	{
//		cur1 = head1;
//		cur2 = head2;
//		int n = 0;
//		while (cur1->next != loop1)
//		{
//			++n;
//			cur1 = cur1->next;
//		}
//		while (cur2->next != loop2)
//		{
//			--n;
//			cur2 = cur2->next;
//		}
//		cur1 = n > 0 ? head1 : head2;
//		cur2 = cur1 == head1 ? head2 : head1;
//		n = abs(n);
//		while (n--)
//		{
//			cur1 = cur1->next;
//		}
//		while (cur1 != cur2)
//		{
//			cur1 = cur1->next;
//			cur2 = cur2->next;
//		}
//		return cur1;
//	}
//	else
//	{
//		cur1 = loop1->next;
//		while (cur1 != loop1)
//		{
//			if (cur1 == loop2)
//			{
//				return loop1;
//			}
//			cur1 = cur1->next;
//		}
//		return NULL;
//	}
//}
//
//SLLNode* GetIntersectionNode(SLLNode* head1, SLLNode* head2)
//{
//	if (head1 == NULL || head2 == NULL)
//	{
//		return NULL;
//	}
//	SLLNode* loop1 = GetLoopNode(head1);
//	SLLNode* loop2 = GetLoopNode(head2);
//	if (loop1 == NULL && loop2 == NULL)
//	{
//		return NoLoop(head1, head2);
//	}
//	if (loop1 != NULL && loop2 != NULL)
//	{
//		return BothLoop(head1, loop1, head2, loop2);
//	}
//	return NULL;
//}
//
//void Test1()
//{
//	printf("******************************01******************************\n");
//	SLLNode* head1;
//	head1 = Create_SinglyLinkedListNode(1);
//	head1->next = Create_SinglyLinkedListNode(2);
//	head1->next->next = Create_SinglyLinkedListNode(3);
//	head1->next->next->next = Create_SinglyLinkedListNode(4);
//	head1->next->next->next->next = Create_SinglyLinkedListNode(5);
//	head1->next->next->next->next->next = Create_SinglyLinkedListNode(6);
//	head1->next->next->next->next->next->next = Create_SinglyLinkedListNode(7);
//
//	SLLNode* head2;
//	head2 = Create_SinglyLinkedListNode(0);
//	head2->next = Create_SinglyLinkedListNode(9);
//	head2->next->next = Create_SinglyLinkedListNode(8);
//
//	head2->next->next->next = head1->next->next->next->next->next;
//
//	printf("%d\n", (GetIntersectionNode(head1, head2))->data);
//	printf("*****************************EXIT*****************************\n\n");
//}
//
//void Test2()
//{
//	printf("******************************02******************************\n");
//	SLLNode* head1;
//	head1 = Create_SinglyLinkedListNode(1);
//	head1->next = Create_SinglyLinkedListNode(2);
//	head1->next->next = Create_SinglyLinkedListNode(3);
//	head1->next->next->next = Create_SinglyLinkedListNode(4);
//	head1->next->next->next->next = Create_SinglyLinkedListNode(5);
//	head1->next->next->next->next->next = Create_SinglyLinkedListNode(6);
//	head1->next->next->next->next->next->next = Create_SinglyLinkedListNode(7);
//	head1->next->next->next->next->next->next->next = head1->next->next->next;
//
//	SLLNode* head2;
//	head2 = Create_SinglyLinkedListNode(0);
//	head2->next = Create_SinglyLinkedListNode(9);
//	head2->next->next = Create_SinglyLinkedListNode(8);
//
//	head2->next->next->next = head1->next;
//
//	printf("%d\n", (GetIntersectionNode(head1, head2))->data);
//	printf("*****************************EXIT*****************************\n\n");
//}
//
//void Test3()
//{
//	printf("******************************03******************************\n");
//	SLLNode* head1;
//	head1 = Create_SinglyLinkedListNode(1);
//	head1->next = Create_SinglyLinkedListNode(2);
//	head1->next->next = Create_SinglyLinkedListNode(3);
//	head1->next->next->next = Create_SinglyLinkedListNode(4);
//	head1->next->next->next->next = Create_SinglyLinkedListNode(5);
//	head1->next->next->next->next->next = Create_SinglyLinkedListNode(6);
//	head1->next->next->next->next->next->next = Create_SinglyLinkedListNode(7);
//	head1->next->next->next->next->next->next->next = head1->next->next->next;
//
//	SLLNode* head2;
//	head2 = Create_SinglyLinkedListNode(0);
//	head2->next = Create_SinglyLinkedListNode(9);
//	head2->next->next = Create_SinglyLinkedListNode(8);
//
//	head2->next->next->next = head1->next->next->next->next->next;
//
//	printf("%d\n", (GetIntersectionNode(head1, head2))->data);
//	printf("*****************************EXIT*****************************\n\n");
//}
//
//int main()
//{
//	Test1();
//	Test2();
//	Test3();
//	return 0;
//}

////有效的括号：https://leetcode.cn/problems/valid-parentheses/。
//bool isValid(char* s)
//{
//	size_t n;
//	if (s == NULL || (n = strlen(s)) == 0)
//		return true;
//	size_t size = 0;
//	char* parr = (char*)malloc(sizeof(char) * n);
//	for (size_t i = 0; i < n; ++i)
//	{
//		char cha = s[i];
//		if (cha == '(' || cha == '[' || cha == '{')
//		{
//			parr[size++] = cha == '(' ? ')' : (cha == '[' ? ']' : '}');
//		}
//		else
//		{
//			if (size == 0)
//				return false;
//			else
//			{
//				char last = parr[--size];
//				if (last != cha)
//					return false;
//			}
//		}
//	}
//	free(parr);
//	return size == 0;
//}

////用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/。
//typedef struct QueueNode
//{
//	int data;
//	struct QueueNode* next;
//} QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//	size_t size;
//} Queue;
//
//typedef struct MyStack
//{
//	Queue queue;
//	Queue help;
//} MyStack;
//
//void Init_Queue(Queue* ptr)
//{
//	assert(ptr);
//	ptr->head = ptr->tail = NULL;
//	ptr->size = 0;
//}
//
//bool Empty_Queue(Queue* ptr)
//{
//	assert(ptr);
//	return ((ptr->head == NULL) && (ptr->tail == NULL));
//}
//
//void Push_Queue(Queue* ptr, int data)
//{
//	assert(ptr);
//	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//	newNode->data = data;
//	newNode->next = NULL;
//	if (ptr->head == NULL && ptr->tail == NULL)
//	{
//		ptr->head = ptr->tail = newNode;
//	}
//	else
//	{
//		ptr->tail->next = newNode;
//		ptr->tail = newNode;
//	}
//	++ptr->size;
//}
//
//void Pop_Queue(Queue* ptr)
//{
//	assert(ptr);
//	assert(!Empty_Queue(ptr));
//	if (ptr->head->next == NULL)
//	{
//		free(ptr->head);
//		ptr->head = ptr->tail = NULL;
//	}
//	else
//	{
//		QueueNode* del = ptr->head;
//		ptr->head = ptr->head->next;
//		free(del);
//	}
//	--ptr->size;
//}
//
//int Front_Queue(Queue* ptr)
//{
//	assert(ptr);
//	assert(!Empty_Queue(ptr));
//	return ptr->head->data;
//}
//
//void Destroy_Queue(Queue* ptr)
//{
//	assert(ptr);
//	QueueNode* cur = ptr->head;
//	while (cur != NULL)
//	{
//		QueueNode* del = cur;
//		cur = cur->next;
//		free(del);
//	}
//	ptr->head = ptr->tail = NULL;
//}
//
//MyStack* myStackCreate()
//{
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	Init_Queue(&obj->queue);
//	Init_Queue(&obj->help);
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	Push_Queue(&obj->queue, x);
//}
//
//int myStackPop(MyStack* obj)
//{
//	while (obj->queue.size > 1)
//	{
//		Push_Queue(&obj->help, Front_Queue(&obj->queue));
//		Pop_Queue(&obj->queue);
//	}
//	int ans = Front_Queue(&obj->queue);
//	Pop_Queue(&obj->queue);
//	Queue tmp = obj->queue;
//	obj->queue = obj->help;
//	obj->help = tmp;
//	return ans;
//}
//
//int myStackTop(MyStack* obj)
//{
//	while (obj->queue.size > 1)
//	{
//		Push_Queue(&obj->help, Front_Queue(&obj->queue));
//		Pop_Queue(&obj->queue);
//	}
//	int ans = Front_Queue(&obj->queue);
//	Pop_Queue(&obj->queue);
//	Push_Queue(&obj->help, ans);
//	Queue tmp = obj->queue;
//	obj->queue = obj->help;
//	obj->help = tmp;
//	return ans;
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return Empty_Queue(&obj->queue);
//}
//
//void myStackFree(MyStack* obj)
//{
//	Destroy_Queue(&obj->queue);
//	Destroy_Queue(&obj->help);
//	free(obj);
//}

////用栈实现队列：https://leetcode-cn.com/problems/implement-queue-using-stacks/。
//typedef int ElemType;
//
//typedef struct StackNode
//{
//	ElemType data;
//	struct StackNode* prev;
//	struct StackNode* next;
//} StackNode;
//
//typedef struct Stack
//{
//	size_t size;
//	StackNode* head;
//	StackNode* tail;
//} Stack;
//
//typedef struct
//{
//	Stack stackPush;
//	Stack stackPop;
//} MyQueue;
//
//void Init_Stack(Stack* ptr)
//{
//	assert(ptr);
//	ptr->size = 0;
//	ptr->head = ptr->tail = NULL;
//}
//
//void Push_Stack(Stack* ptr, ElemType data)
//{
//	assert(ptr);
//	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
//	if (newNode == NULL)
//	{
//		perror("Push_Stack");
//		exit(EXIT_FAILURE);
//	}
//	newNode->data = data;
//	newNode->prev = newNode->next = NULL;
//	if (ptr->head == NULL)
//	{
//		ptr->head = ptr->tail = newNode;
//	}
//	else
//	{
//		ptr->head->prev = newNode;
//		newNode->next = ptr->head;
//		ptr->head = newNode;
//	}
//	++ptr->size;
//}
//
//bool Empty_Stack(Stack* ptr)
//{
//	assert(ptr);
//	return ptr->size == 0;
//}
//
//ElemType Pop_Stack(Stack* ptr)
//{
//	assert(ptr);
//	assert(!Empty_Stack(ptr));
//	ElemType ans = ptr->head->data;
//	if (ptr->head == ptr->tail)
//	{
//		free(ptr->head);
//		ptr->head = ptr->tail = NULL;
//	}
//	else
//	{
//		ptr->head = ptr->head->next;
//		free(ptr->head->prev);
//		ptr->head->prev = NULL;
//	}
//	--ptr->size;
//	return ans;
//}
//
//ElemType Top_Stack(Stack* ptr)
//{
//	assert(ptr);
//	return ptr->head->data;
//}
//
//void Destroy_Stack(Stack* ptr)
//{
//	assert(ptr);
//	while (ptr->head)
//	{
//		if (ptr->head->next == NULL)
//		{
//			free(ptr->head);
//			break;
//		}
//		ptr->head = ptr->head->next;
//		free(ptr->head->prev);
//	}
//	ptr->head = ptr->tail = NULL;
//}
//
//void PushToPop(MyQueue* obj)
//{
//	if (Empty_Stack(&obj->stackPop))
//	{
//		while (!Empty_Stack(&obj->stackPush))
//		{
//			Push_Stack(&obj->stackPop, Pop_Stack(&obj->stackPush));
//		}
//	}
//}
//
//MyQueue* myQueueCreate()
//{
//	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//	Init_Stack(&obj->stackPush);
//	Init_Stack(&obj->stackPop);
//	return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//	Push_Stack(&obj->stackPush, x);
//	PushToPop(obj);
//}
//
//int myQueuePop(MyQueue* obj)
//{
//	assert(!(Empty_Stack(&obj->stackPush) && Empty_Stack(&obj->stackPop)));
//	PushToPop(obj);
//	return Pop_Stack(&obj->stackPop);
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//	assert(!(Empty_Stack(&obj->stackPush) && Empty_Stack(&obj->stackPop)));
//	PushToPop(obj);
//	return Top_Stack(&obj->stackPop);
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//	return (Empty_Stack(&obj->stackPush) && Empty_Stack(&obj->stackPop));
//}
//
//void myQueueFree(MyQueue* obj)
//{
//	Destroy_Stack(&obj->stackPop);
//	Destroy_Stack(&obj->stackPush);
//	free(obj);
//}

////设计循环队列：https://leetcode-cn.com/problems/design-circular-queue/。
//typedef struct
//{
//	int* array_ptr;
//	size_t push_index;
//	size_t pop_index;
//	size_t size;
//	size_t capacity;
//} MyCircularQueue;
//
//size_t NextIndex(size_t limit, size_t index)
//{
//	return index < limit - 1 ? index + 1 : 0;
//}
//
//MyCircularQueue* myCircularQueueCreate(size_t k)
//{
//	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	obj->capacity = k;
//	obj->array_ptr = (int*)malloc(sizeof(int) * obj->capacity);
//	obj->push_index = obj->pop_index = obj->size = 0;
//	return obj;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	assert(obj);
//	return obj->size == 0;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	assert(obj);
//	return obj->size == obj->capacity;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	assert(obj);
//	if (myCircularQueueIsFull(obj))
//	{
//		return false;
//	}
//	++obj->size;
//	obj->array_ptr[obj->push_index] = value;
//	obj->push_index = NextIndex(obj->capacity, obj->push_index);
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	assert(obj);
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return false;
//	}
//	--obj->size;
//	obj->pop_index = NextIndex(obj->capacity, obj->pop_index);
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	assert(obj);
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	return obj->array_ptr[obj->pop_index];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	assert(obj);
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	if (obj->push_index == 0)
//	{
//		return obj->array_ptr[obj->capacity - 1];
//	}
//	return obj->array_ptr[obj->push_index - 1];
//}
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	assert(obj);
//	free(obj->array_ptr);
//	free(obj);
//}

////二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/。
//size_t Tree_Size(struct TreeNode* root)
//{
//	return root == NULL ? 0 : Tree_Size(root->left) + Tree_Size(root->right) + 1;
//}
//
//void pre(struct TreeNode* root, int* array, int* arraySize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	array[(*arraySize)++] = root->val;
//	pre(root->left, array, arraySize);
//	pre(root->right, array, arraySize);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//	int* array = (int*)malloc(sizeof(int) * Tree_Size(root));
//	*returnSize = 0;
//	pre(root, array, returnSize);
//	return array;
//}

////单值二叉树：https://leetcode.cn/problems/univalued-binary-tree/。
//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//	if (root->left && root->val != root->left->val || !isUnivalTree(root->left))
//	{
//		return false;
//	}
//	if (root->right && root->val != root->right->val || !isUnivalTree(root->right))
//	{
//		return false;
//	}
//	return true;
//}

////二叉树的最大深度：https://leetcode.cn/problems/maximum-depth-of-binary-tree/。
//int maxDepth(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int leftHeight = maxDepth(root->left);
//	int rightHeight = maxDepth(root->right);
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}

////翻转二叉树：https://leetcode.cn/problems/invert-binary-tree/submissions/。
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	struct TreeNode* leftTree = invertTree(root->left);
//	struct TreeNode* rightTree = invertTree(root->right);
//	root->left = rightTree;
//	root->right = leftTree;
//	return root;
//}

////相同的树：https://leetcode.cn/problems/same-tree/。
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL ^ q == NULL)
//	{
//		return false;
//	}
//	if (p == NULL && q == NULL)
//	{
//		return true;
//	}
//	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

////对称二叉树：https://leetcode.cn/problems/symmetric-tree/submissions/。
//bool isMirror(struct TreeNode* head1, struct TreeNode* head2)
//{
//	if (head1 == NULL ^ head2 == NULL)
//	{
//		return false;
//	}
//	if (head1 == NULL && head2 == NULL)
//	{
//		return true;
//	}
//	return head1->val == head2->val && isMirror(head1->left, head2->right) && isMirror(head1->right, head2->left);
//}
//
//bool isSymmetric(struct TreeNode* root)
//{
//	return isMirror(root, root);
//}

////另一棵树的子树：https://leetcode.cn/problems/subtree-of-another-tree/submissions/。
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL ^ q == NULL)
//	{
//		return false;
//	}
//	if (p == NULL && q == NULL)
//	{
//		return true;
//	}
//	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//	if (root == NULL)
//	{
//		return false;
//	}
//	if (isSameTree(root, subRoot))
//	{
//		return true;
//	}
//	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}

////平衡二叉树：https://leetcode.cn/problems/balanced-binary-tree/。
//typedef struct Info
//{
//	bool isBalanced;
//	size_t height;
//} Info;
//
//Info info(bool isBalanced, size_t height)
//{
//	Info info = { isBalanced, height };
//	return info;
//}
//
//Info process(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return info(true, 0);
//	}
//	Info left = process(root->left);
//	Info right = process(root->right);
//	size_t height = fmax(left.height, right.height) + 1;
//	bool isBalanced = true;
//	if (!left.isBalanced)
//	{
//		isBalanced = false;
//	}
//	if (!right.isBalanced)
//	{
//		isBalanced = false;
//	}
//	if (abs(left.height - right.height) > 1)
//	{
//		isBalanced = false;
//	}
//	return info(isBalanced, height);
//}
//
//bool isBalanced(struct TreeNode* root)
//{
//	return process(root).isBalanced;
//}