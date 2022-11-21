
// 执行结果：
// 解答错误
// 显示详情
// 添加备注

// 通过测试用例：
// 285 / 353
// 输入：
// "aaa"
// "ab*ac*a"
// 输出：
// false
// 预期结果：
// true
// 匹配0个即为删除前一个字符！！！
bool MyIsMatchRecur(char *s, char *p) {
    bool asteriskChaFlag = false;
    char asteriskCha;
    char *Pbk = p;
    char *Sbk = s;
    
    while (*p != '\0' && *s != '\0') {
        if (*p == '.') {
            s++;
            p++;
            continue;
        }
        if (*p == '*') {
            asteriskChaFlag = true;
            p--;
            asteriskCha = *p;
            p++;

            if (asteriskCha == '.' || asteriskCha == *s) {
                s++;
                continue;
            } else {
                p++;
                continue;
            }
        } else if (*p == *s){
            s++;
            p++;
        } else {
            s = Sbk;
            p++;
        }
    }
    if (*s == '\0' && *p != '\0') {
        if (*p != '*')
            return false;
        p++;
        while (*p != '\0') {
            if (*p == '.') {
                p++;
            } else if (*p == asteriskCha) {
                p++;
            } else {
                break;
            }
        }
        if (*p == '\0')
            return true;
        else
            return false;
    }
    if (*s == '\0' && *p == '\0')
        return true;
    return false;
}

bool isMatch(char * s, char * p){
    return MyIsMatchRecur( s, p);
}