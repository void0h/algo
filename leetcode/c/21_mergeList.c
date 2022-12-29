/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 输入：
// [2]
// [1]
// 输出：
// [1]
// 预期结果：
// [1,2]
struct ListNode* mergeTwoLists01(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *list1_next = NULL;
    struct ListNode *list2_next = NULL;
    struct ListNode *list = NULL;

    if (list1 == NULL || list2 == NULL)
        return list1 != NULL ? list1 : list2;

    if (list1->val > list2->val)
        list = list2;
    else
        list = list1;

    while (list1 && list2) {
        if (list2->val >= list1->val && ((list1->next == NULL) ||list2->val <= list1->next->val)) {
            list1_next = list1->next;
            list2_next = list2->next;
            list1->next = list2;

            list2->next = list1_next;
            list2 = list2_next;
            list1 = list1->next;
        } else if (list1->val > list2->val) {
            list2 = list2->next;
        } else {
            list1 = list1->next;
        }
    }

    return list;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 执行用时：4 ms, 在所有 C 提交中击败了76.32%的用户
// 内存消耗：5.8 MB, 在所有 C 提交中击败了84.95%的用户
// 通过测试用例：208 / 208
struct ListNode* mergeTwoLists02(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *list1_next = NULL;
    struct ListNode *list2_next = NULL;
    struct ListNode *list = NULL;

    if (list1 == NULL || list2 == NULL)
        return list1 != NULL ? list1 : list2;

    if (list1->val > list2->val)
        list = list2;
    else
        list = list1;

    while (list1 && list2) {
        if (list1->val == list2->val) {
            list1_next = list1->next;
            list2_next = list2->next;
            list1->next = list2;    //需要保证list1为保存了低序的链 list1: 2-3-4 list2: 0-1-2-3则出错
            list2->next = list1_next;
            list1 = list1->next;
            list2 = list2_next;
        } else if (list1->val > list2->val) {
            if (list2->next == NULL) {
                list2->next = list1;
                list2 = NULL;
            } else if (list2->next->val < list1->val) {
                list2 = list2->next;
            } else {
                list1_next = list1->next;
                list2_next = list2->next;
                list2->next = list1;
                list1->next = list2_next;
                list1 = list2->next;    //将list1设为保存低序的链表 list2 = list2->next;
                list2 = list1_next;
            }
        } else {    //list1->val < list2->val
            if (list1->next == NULL) {
                list1->next = list2;
                list1 = NULL;
            } else if (list1->next->val < list2->val) {
                list1 = list1->next;
            } else {
                list1_next = list1->next;
                list2_next = list2->next;
                list1->next = list2;
                list2->next = list1_next;
                list1 = list1->next;
                list2 = list2_next;
            }
        }
    }

    return list;
}


/*****************************看过题解后***********************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}