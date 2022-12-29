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
// 5.6 MB
// , 在所有 C 提交中击败了
// 11.40%
// 的用户
// 通过测试用例：
// 1108 / 1108
bool isPowerOfTwo(int n){
    if (n <= 0)
        return false;
    if (n == 1 || n == 2)
        return true;

    while (n > 1) {
        if ( n % 2 )
            return false;
        n = n/2;
    }
    return true;
}

bool isPowerOfTwo(int n){
    if (n <= 0 || (n > 2 && (n % 2) != 0))
        return false;
    if (n == 1)
        return true;
    n /= 2;
    return isPowerOfTwo(n);
}