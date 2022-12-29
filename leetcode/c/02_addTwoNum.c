/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//出错！
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    static int flag = 0;
    if (l1 == NULL && l2 == NULL) {
        if (flag) {
            struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = 1;
            node->next = NULL;
            return node;
        } else {
            return NULL;
        }
    }

    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (l1)
        node->val = l1->val;
    if (l2)
        node->val += l2->val;
    node->val += flag;
    if (node->val >= 10)
        flag = 1;
    else
        flag = 0;
    node->val = node->val % 10;
    if (l1 && l2)
        node->next = addTwoNumbers(l1->next, l2->next);
    else if (l1)
        node->next = addTwoNumbers(l1->next, NULL);
    else
        node->next = addTwoNumbers(NULL, l2->next);
    return node;
}

/*****************************看过题解后***********************************/

// 执行用时：
// 12 ms
// , 在所有 C 提交中击败了
// 80.25%
// 的用户
// 内存消耗：
// 8.6 MB
// , 在所有 C 提交中击败了
// 5.31%
// 的用户
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    int sum = l1->val + l2->val;
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = sum%10;
    node->next = addTwoNumbers(l1->next, l2->next);
    if (sum > 9) {
        struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        node1->val = 1;
        node1->next = NULL;
        node->next = addTwoNumbers(node->next, node1);
    }

    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int flag = 0;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    l1->val += l2->val;
    if (l1->val >= 10) {
        flag = 1;
        l1->val %= 10;
    }
    l1->next = addTwoNumbers(l1->next, l2->next);
    if (flag) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        l1->next = addTwoNumbers(l1->next, node);
    }
    return l1;
}