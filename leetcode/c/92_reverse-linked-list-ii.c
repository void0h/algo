/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *l, struct ListNode *r)
{
    struct ListNode *cur = l;
    struct ListNode *next;
    struct ListNode *prev = r != NULL ? r->next : NULL;

    if (l == r || l == NULL || r == NULL)
        return l;
    while (cur != r) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    cur->next = prev;
    return cur;
}

// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 4 ms
// , 在所有 C 提交中击败了
// 37.19%
// 的用户
// 内存消耗：
// 5.5 MB
// , 在所有 C 提交中击败了
// 96.69%
// 的用户
// 通过测试用例：
// 44 / 44
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *left_node = NULL;
    struct ListNode *right_node = NULL;
    struct ListNode *new_head = NULL;
    struct ListNode *new_tail = NULL;

    if (left == right || left > right)
        return head;

    if (left > 1)
        new_head = head;
    for (int i = 1; i < left; i++) {
        if (new_tail ==  NULL)
            new_tail = head;
        else
            new_tail = new_tail->next;
        head = head->next;
    }
    left_node = head;
    for (int i = left; i < right; i++) {
        head = head->next;
    }
    right_node = head;
    if (new_head == NULL)
        new_head = reverse(left_node, right_node);
    else
        new_tail->next = reverse(left_node, right_node);
    return new_head;
}

/*****************************看过题解后***********************************/
