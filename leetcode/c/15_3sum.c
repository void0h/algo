/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*****************************看过题解后***********************************/


int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 232 ms
// , 在所有 C 提交中击败了
// 7.77%
// 的用户
// 内存消耗：
// 31.6 MB
// , 在所有 C 提交中击败了
// 31.15%
// 的用户
// 通过测试用例：
// 312 / 312
void my_qsort(int *nums, int left, int right)
{
    int value = nums[right];
    int i = left, j = left;
    int temp;

    if (left >= right)
        return;

    while (j < right) {
        if (value > nums[j]) {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
        }
        j++;
    }
    nums[right] = nums[i];
    nums[i] = value;
    my_qsort(nums, left, i-1);
    my_qsort(nums, i+1, right);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int first, second, third;
    int **arr;
    
    my_qsort(nums,  0, numsSize -1);
    // qsort(nums, numsSize, sizeof(int), comp);
    arr = (int **)malloc(sizeof(int **)*numsSize*numsSize);
    *returnSize = 0;
    for (first = 0; first < numsSize; first++) {
        if (nums[first] > 0)
            break;
        if (first > 0 && nums[first] == nums[first-1])
            continue;
        third = numsSize-1;
        for (second = first+1; second < numsSize; second++) {
            if (second > first+1 && nums[second] == nums[second-1] 
                || (nums[first]+nums[second]+nums[third]) < 0)
                continue;

            while (second < third && (nums[first]+nums[second]+nums[third]) > 0)
                third--;

            if (second == third)
                break;

            if ((nums[first]+nums[second]+nums[third]) == 0) {
                arr[*returnSize] = (int *)malloc(sizeof(int)*3);
                arr[*returnSize][0] = nums[first];
                arr[*returnSize][1] = nums[second];
                arr[*returnSize][2] = nums[third];
                *returnSize += 1;
            }
        }
        
    }

    *returnColumnSizes = (int*)malloc((*returnSize) *sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 3;
    return arr;
}