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
// 5.4 MB
// , 在所有 C 提交中击败了
// 44.13%
// 的用户
// 通过测试用例：
// 1032 / 1032
int reverse(int x){
    int nagtive = x < 0 ? -1 : 1;
    int sum = 0;
    if (x < 0) {
        if (x == 0x80000000)
            return 0;
        x = -x;
    }
        
    while (x) {
        if (sum > 0x7fffffff/10)
            return 0;
        sum = sum * 10 + x%10;
        x /= 10;
    }

    return nagtive * sum;
}