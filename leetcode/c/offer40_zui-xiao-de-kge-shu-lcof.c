/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// void my_qsort(int *arr, int l, int r)
// {
//     int temp;
//     int value = arr[r];
//     int i = l, j = l;

//     if (l >= r)
//         return;
        
//     while (j < r) {
//         if (value > arr[j]) {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i++;
//             j++;
//         } else {
//             j++;
//         }
//     }
//     temp = arr[i];
//     arr[i] = arr[r];
//     arr[r] = temp;
//     my_qsort(arr, l, i-1);
//     my_qsort(arr, i+1, r);
// }

void k_qsort(int *arr, int l, int r, int k)
{
    int temp;
    int value = arr[r];
    int i = l, j = l;

    if (l >= r)
        return;
        
    while (j < r) {
        if (value > arr[j]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        } else {
            j++;
        }
    }
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    if (k == i)
        return;
    if (k < i)
        k_qsort(arr, l, i-1, k);
    else
        k_qsort(arr, i+1, r, k);
}
// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 48 ms
// , 在所有 C 提交中击败了
// 94.25%
// 的用户
// 内存消耗：
// 10.2 MB
// , 在所有 C 提交中击败了
// 93.49%
// 的用户
// 通过测试用例：
// 39 / 39
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    // my_qsort(arr, 0, arrSize-1);
    k_qsort(arr, 0, arrSize-1, k);
    *returnSize = k;
    return arr;
}