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
// 16 ms
// , 在所有 C 提交中击败了
// 79.21%
// 的用户
// 内存消耗：
// 9.4 MB
// , 在所有 C 提交中击败了
// 10.46%
// 的用户
// 通过测试用例：
// 12 / 12
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head;

    if (head == NULL || head->next == NULL)
        return head;
    new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;     
}

struct ListNode *midNode(struct ListNode *head)
{
    struct ListNode *slow, *fast;
    struct ListNode *prev = NULL;
    if (head == NULL && head->next == NULL)
        return head;
    slow = head;
    fast = head->next;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) {
        prev = slow;
        slow = slow->next;
    }
    if (prev)
        prev->next = NULL;
    return slow;
}

void mergeList(struct ListNode *list1, struct ListNode *list2)
{
    
    struct ListNode *tail1 = list1;
    struct ListNode *tail2 = list2;
    struct ListNode *temp1, *temp2;

    if (tail1 == NULL)
        return ;
    while (tail1->next) {

        temp1 = tail1->next;
        temp2 = tail2->next;
        tail1->next = tail2;
        tail2->next = temp1;
        tail1 = temp1;
        tail2 = temp2;
    }
    tail1->next = tail2;
}

void reorderList(struct ListNode* head){
    struct ListNode *resList;
    struct ListNode *mid;
    
    if (head == NULL || head->next == NULL)
        return;

    mid = midNode(head);
    resList = reverseList(mid);
    mergeList(head, resList);
}