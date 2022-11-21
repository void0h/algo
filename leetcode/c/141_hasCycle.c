/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 执行用时：12 ms, 在所有 C 提交中击败了36.10%的用户
// 内存消耗：7.7 MB, 在所有 C 提交中击败了44.94%的用户
// 
bool hasCycle01(struct ListNode *head) {
    struct ListNode *step = NULL;
    struct ListNode *two_step = NULL;

    if (head == NULL || head->next == NULL)
        return false;
    step = head;
    two_step = head;
    while (two_step) {
        step = step->next;
        two_step = two_step->next;
        if (two_step)
            two_step = two_step->next;
        
        if (step == two_step)
            return true;
    }
    return false;
}


/*****************************看过题解后***********************************/

