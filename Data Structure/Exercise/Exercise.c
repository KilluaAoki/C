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