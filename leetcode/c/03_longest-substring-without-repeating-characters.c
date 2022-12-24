
// 执行用时：
// 256 ms
// , 在所有 C 提交中击败了
// 6.65%
// 的用户
// 内存消耗：
// 5.8 MB
// , 在所有 C 提交中击败了
// 40.19%
// 的用户
// 通过测试用例：
// 987 / 987
int lengthOfLongestSubstring(char * s){
    int left = 0;
    int max_len = 0;
    int repeat = 0;
    int repeat_pos = 0;

    for (int i = 0; i < strlen(s); i++) {
        repeat = 0;
        for (int j = left; j < i; j++) {
            if (i != j && s[i] == s[j]) {
                repeat = 1;
                repeat_pos = j;
                break;
            }
        }
        if (repeat == 0) {
            if (max_len < (i-left+1))
                max_len = i - left + 1;
        } else {
            left = repeat_pos+1;
            i = left;
        }
    }
    return max_len;
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
// 5.7 MB
// , 在所有 C 提交中击败了
// 50.51%
// 的用户
// 通过测试用例：
// 987 / 987
int lengthOfLongestSubstring(char * s){
    char tmp[128] = {0};
    int right = 0;
    int left = 0;
    int cnt = 0;
    int res = 0;

    while (s[right] != '\0') {
        if (tmp[s[right]] == 0) {
            tmp[s[right]] = 1;
            right++;
            cnt++;
            res = res > cnt ? res : cnt;
        } else {
            tmp[s[left]] = 0;
            left++;
            cnt--;
        }
    }
    return res;
}