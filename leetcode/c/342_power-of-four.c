// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 4 ms
// , 在所有 C 提交中击败了
// 41.04%
// 的用户
// 内存消耗：
// 5.4 MB
// , 在所有 C 提交中击败了
// 49.28%
// 的用户
// 通过测试用例：
// 1061 / 1061
bool isPowerOfFour(int n){
    if (n == 1)
        return true;
    if (n == 0)
        return false;
    
    while (n > 3) {
        if (n % 4)
            return false;
        n = n/4;
    }
    if (n == 1)
        return true;
    return false;
}
// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 0 ms
// , 在所有 C 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.3 MB
// , 在所有 C 提交中击败了
// 84.05%
// 的用户
// 通过测试用例：
// 1061 / 1061
bool isPowerOfFour(int n){
    if (n == 4 || n == 1)
        return true;
    if (n%4 || n <= 0)
        return false;
    return isPowerOfFour(n/4);
}