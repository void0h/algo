/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 12 ms
// , 在所有 C 提交中击败了
// 71.24%
// 的用户
// 内存消耗：
// 7.8 MB
// , 在所有 C 提交中击败了
// 80.59%
// 的用户
// 通过测试用例：
// 66 / 66
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *temp = head;
    struct ListNode *prev = NULL;
    while (temp) {
        if (temp->val == val) {
            if (prev == NULL) {
                head = temp->next;
                free(temp);
                temp = head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }

        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}