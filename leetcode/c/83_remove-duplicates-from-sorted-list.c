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
// 8 ms
// , 在所有 C 提交中击败了
// 31.68%
// 的用户
// 内存消耗：
// 6.2 MB
// , 在所有 C 提交中击败了
// 71.41%
// 的用户
// 通过测试用例：
// 166 / 166
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *temp = head;
    struct ListNode *next = NULL;

    while (temp && temp->next) {
        if (temp->val == temp->next->val) {
            next = temp->next->next;
            free(temp->next);
            temp->next = next;
        } else {
            temp = temp->next;
        }
    }
    return head;
}