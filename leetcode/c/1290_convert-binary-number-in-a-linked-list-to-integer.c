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
// 0 ms
// , 在所有 C 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.4 MB
// , 在所有 C 提交中击败了
// 83.49%
// 的用户
// 通过测试用例：
// 102 / 102
int getDecimalValue(struct ListNode* head){
    int val = 0;

    while (head) {
        val = (val << 1) | head->val;
        head = head->next;
    }
    return val;
}