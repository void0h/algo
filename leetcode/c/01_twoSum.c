/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 执行用时：
// 72 ms
// , 在所有 C 提交中击败了
// 86.50%
// 的用户
// 内存消耗：
// 6.4 MB
// , 在所有 C 提交中击败了
// 25.50%
// 的用户
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *sum = malloc(sizeof(int)*2);
    if (sum == NULL)
        return NULL;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                sum[0] = i;
                sum[1] = j;
                *returnSize = 2;
                return sum;
            }
        }
    }
    return NULL;
}
