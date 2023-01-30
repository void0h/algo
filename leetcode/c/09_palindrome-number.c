// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 4 ms
// , 在所有 C 提交中击败了
// 93.38%
// 的用户
// 内存消耗：
// 5.7 MB
// , 在所有 C 提交中击败了
// 76.19%
// 的用户
// 通过测试用例：
// 11510 / 11510
bool isPalindrome(int x){
    unsigned long long y = 0;
    int temp = x;

    if (x < 0)
        return false;
    
    while (temp) {
        y = y * 10 + temp%10;
        temp /= 10;
    }
    if (x == y)
        return true;
    return false;
}