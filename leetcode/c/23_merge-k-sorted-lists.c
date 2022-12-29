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
// 404 ms
// , 在所有 C 提交中击败了
// 5.27%
// 的用户
// 内存消耗：
// 8.5 MB
// , 在所有 C 提交中击败了
// 33.84%
// 的用户
// 通过测试用例：
// 133 / 133
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode head = {.val=0x0, .next=NULL};
    struct ListNode *temp = NULL, *last = NULL;
    int minList = 0;

    do {
        temp = NULL;
        for (int i = 0; i < listsSize; i++) {
            if (lists[i] == NULL)
                continue;
            if (temp == NULL)
                minList = i;
            if (lists[minList]->val >= lists[i]->val) {
                minList = i;
                temp = lists[i];
            }
        }
        if (temp) {
            // struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            // if (node == NULL)
            //     goto ERR;
            // node->val = lists[minList]->val;
            // node->next = NULL;
            // lists[minList] = lists[minList]->next;
            if (head.next == NULL) {
                head.next = lists[minList];
                last = lists[minList];
            } else {
                last->next = lists[minList];
                last = lists[minList];
            }
            lists[minList]= lists[minList]->next;
        }
    } while (temp);

    return head.next;

// ERR:
//     return NULL;
}