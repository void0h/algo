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
// 81.45%
// 的用户
// 通过测试用例：
// 1083 / 1083
int myAtoi(char * s){
    int sign = 1;
    int sum = 0;

    while (*s != '\0') {
        if (*s == ' ') {
            s++;
            continue;
        } else if (*s == '+') {
            s++;
            break;
        } else if (*s == '-') {
            s++;
            sign = -1;
            break;
        } else if (*s >= '0' && *s <= '9') {
            break;
        } else {
            return 0;
        }
    }

    while (*s >= '0' && *s <= '9') {
        if (sum == INT_MAX/10) {
            if (sign == 1 && (*s >= INT_MAX%10+'0'))
                return INT_MAX;
            else if (sign == -1 && (*s >= (INT_MAX%10+'0' + 1)))
                return INT_MIN;
        } else if (sum > INT_MAX/10)
            return sign == 1? INT_MAX : INT_MIN;
        sum = sum * 10 + (*s - '0');
        s++;
    }
    return sign*sum;
}