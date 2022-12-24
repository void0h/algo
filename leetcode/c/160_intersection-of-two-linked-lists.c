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
// 32 ms
// , 在所有 C 提交中击败了
// 79.65%
// 的用户
// 内存消耗：
// 13.7 MB
// , 在所有 C 提交中击败了
// 34.43%
// 的用户
// 通过测试用例：
// 39 / 39
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *headA_temp = NULL;
    struct ListNode *headB_temp = NULL;
    struct ListNode *temp = NULL;
    int headA_len = 0;
    int headB_len = 0;
    int len = 0;

    temp = headA;
    while (temp) {
        headA_len++;
        if (temp->next == NULL) {
            headA_temp = temp;
            break;
        }
        temp = temp->next;
    }
    temp = headB;
    while (temp) {
        headB_len++;
        if (temp->next == NULL) {
            headB_temp = temp;
            break;
        }
        temp = temp->next;
    }
    if (headA_temp != headB_temp)
        return NULL;
        
    headA_temp = headA;
    headB_temp = headB;
    if (headA_len > headB_len) {
        len = headA_len - headB_len;
        while (len--) {
            headA_temp = headA_temp->next;
        }
    } else {
        len = headB_len - headA_len;
        while (len--) {
            headB_temp = headB_temp->next;
        }
    }
    while (headA_temp) {
        if (headA_temp == headB_temp)
            return headA_temp;
        headA_temp = headA_temp->next;
        headB_temp = headB_temp->next;
    }
    return NULL;
}