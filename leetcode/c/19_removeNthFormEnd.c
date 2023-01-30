/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 执行用时：0 ms, 在所有 C 提交中击败了100%的用户 
// 内存消耗：5.6 MB, 在所有 C 提交中击败了83.55%的用户
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode *tail = head;
    struct ListNode *del = NULL;
    struct ListNode *temp = NULL;

    if (n <= 0 || head == NULL)
        return head;

    while (tail != NULL) {
        if (n > 0) {
            --n;
        } else {
            if (del == NULL)
                del = head;
            else
                del = del->next;
        }
        tail = tail->next;
    }
    if (del != NULL) {
        temp = del->next;
        del->next = temp->next;
        free(temp);
    }
    if (del == NULL && n == 0) {
        temp = head->next;
        free(head);
        head = temp;
    }
    return head;
}


/*****************************看过题解后***********************************/


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    static int Nth;
    if (head == NULL) {
        Nth = 0;
        return head;
    }
    head->next = removeNthFromEnd(head->next, n);
    Nth++;
    if (Nth == n) {
        struct ListNode *temp = head->next;
        free(head);
        return temp;
    }
    return head;
}