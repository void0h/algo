// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 4 ms
// , 在所有 C 提交中击败了
// 54.12%
// 的用户
// 内存消耗：
// 5.7 MB
// , 在所有 C 提交中击败了
// 70.88%
// 的用户
// 通过测试用例：
// 124 / 124
char * longestCommonPrefix(char ** strs, int strsSize){
    int len = 0;
    char ch;
    int i = 0, j = 0;
    char *pre_str = NULL;

    if (strs == NULL || strsSize <= 0)
        return NULL;
    while (strs[0][i] != '\0') {
        ch = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0')
                goto OUT;
            if (strs[j][i] != ch)
                goto OUT;
        }
        len++;
        i++;
    }
OUT:
    if (len) {
        pre_str = (char *)malloc(len+1);
        memcpy(pre_str, strs[0], len);
        pre_str[len] = '\0';
    }
    return pre_str == NULL ? "": pre_str;
}