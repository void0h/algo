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
// 5.7 MB
// , 在所有 C 提交中击败了
// 57.79%
// 的用户
// 通过测试用例：
// 55 / 55
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* node1 = NULL;
    struct ListNode* node2 = NULL;
    struct ListNode* temp = NULL;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node1 = head;
    node2 = head->next;

    temp = head->next->next;
    head->next->next = head;
    head->next = swapPairs(temp);

    return node2;
}