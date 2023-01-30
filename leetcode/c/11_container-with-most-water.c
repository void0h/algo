// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 80 ms
// , 在所有 C 提交中击败了
// 52.24%
// 的用户
// 内存消耗：
// 11.4 MB
// , 在所有 C 提交中击败了
// 72.75%
// 的用户
// 通过测试用例：
// 61 / 61
int maxArea(int* height, int heightSize){
    int l = 0;
    int r = heightSize - 1;
    int max_area = 0;
    int h = 0;

    while (r > l) {
        h = height[l] > height[r] ? height[r] : height[l];
        if (max_area < h * (r-l))
            max_area = h * (r-l);
        if (height[l] > height[r])
            r--;
        else
            l++;
    }
    return max_area;
}