/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getListLen(struct ListNode *head)
{
    int len = 0;
    struct ListNode *temp = head;

    while (temp) {
        len++;
        temp = temp->next;
    }
    return len;
}
// 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
// 内存消耗：5.8 MB, 在所有 C 提交中击败了19.94%的用户
struct ListNode* middleNode(struct ListNode* head){
    int mid;
    
    if (head == NULL)
        return NULL;

    mid = getListLen(head);
    mid = mid/2 + 1;

    while (--mid > 0) {
        head = head->next;
    }
    return head;
}
