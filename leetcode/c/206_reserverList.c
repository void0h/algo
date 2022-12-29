
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

/*****************************看过题解后***********************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *cur = NULL;
    struct ListNode *next = NULL;

    if (head == NULL)
        return head;
    cur = head;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        if (next == NULL)
            break;
        cur = next;
    }
    return cur;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *new_head;
    if (head == NULL || head->next == NULL)
        return head;
    new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}