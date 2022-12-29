// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 8 ms
// , 在所有 C 提交中击败了
// 92.84%
// 的用户
// 内存消耗：
// 6.2 MB
// , 在所有 C 提交中击败了
// 16.12%
// 的用户
// 通过测试用例：
// 21040 / 21040
bool isPowerOfThree(int n){
    if (n <= 0 || (n>3 && n%3 != 0))
        return false;
    if (n == 1)
        return true;
    n /= 3;
    return isPowerOfThree(n);
}