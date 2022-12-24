bool isPa(char *s, int s_len, int *pa_len)
{
    for (int i = 0; i < s_len/2; i++) {
        if (s[i] != s[s_len-1-i])
            return false;
    }
    *pa_len = s_len;
    return true;
}
// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 1188 ms
// , 在所有 C 提交中击败了
// 7.60%
// 的用户
// 内存消耗：
// 6 MB
// , 在所有 C 提交中击败了
// 55.97%
// 的用户
// 通过测试用例：
// 141 / 141
char * longestPalindrome(char * s){
    char *pa_max = NULL;
    int pa_len = 0;
    int pa_max_len = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = len; j > 0; j--) {
            if (isPa(&s[i], j-i, &pa_len) && 
                pa_len > pa_max_len) {
                pa_max_len = pa_len;
                pa_max = &s[i];
                break;
            }
        }
    }
    if (pa_max_len) {
        pa_max[pa_max_len] = '\0';
    }

    return pa_max;
}