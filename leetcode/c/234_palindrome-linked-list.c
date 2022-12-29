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
// 116 ms
// , 在所有 C 提交中击败了
// 83.43%
// 的用户
// 内存消耗：
// 41.5 MB
// , 在所有 C 提交中击败了
// 32.19%
// 的用户
// 通过测试用例：
// 88 / 88
bool isPalindrome(struct ListNode* head){
    int len = 0;
    struct ListNode *temp = head;

    while (temp) {
        temp = temp->next;
        len++;
    }
    if (len == 1)
        return true;
    else if (len == 0)
        return false;

    char *arr = (char *)malloc(len);
    temp = head;
    len = 0;
    while (temp) {
        arr[len++] = temp->val;
        temp = temp->next;
    }
    for (int j = 0; j < len/2; j++) {
        if (arr[j] != arr[len-1-j])
            return false;
    }

    return true;
}