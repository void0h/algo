
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 执行用时：4 ms, 在所有 C 提交中击败了72.75%的用户
// 内存消耗：6.1 MB, 在所有 C 提交中击败了70.97%的用户
// 22/11/29
struct ListNode* reverseList01(struct ListNode* head){
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;

    if (head == NULL)
        return NULL;
    next = head->next;

    while (next != NULL) {
        head->next = prev;
        prev = head;
        head = next;
        next = head->next;
    }
    head->next = prev;
    return head;
}