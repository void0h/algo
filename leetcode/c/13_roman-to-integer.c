#define C_I  'I'
#define C_V  'V'
#define C_X  'X'
#define C_L  'L'
#define C_C  'C'
#define C_D  'D'
#define C_M  'M'

#define C_I_V  1
#define C_V_V  5
#define C_X_V  10
#define C_L_V  50
#define C_C_V  100
#define C_D_V  500
#define C_M_V  1000

// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 4 ms
// , 在所有 C 提交中击败了
// 87.81%
// 的用户
// 内存消耗：
// 5.8 MB
// , 在所有 C 提交中击败了
// 40.16%
// 的用户
// 通过测试用例：
// 3999 / 3999
int romanToInt(char * s){
    int sum = 0;
    int value = 0;
    char *p = s;

    while (*p != '\0') {
        value = 0;
        switch (*p) {
        case C_I:
            if (*(p+1) == C_V) {
                value = 4;
                p++;
            } else if (*(p+1) == C_X) {
                value = 9;
                p++;
            } else {
                value = C_I_V;
            }
            break;
        case C_V:
            value = C_V_V;
            break;
        case C_X:
            if (*(p+1) == C_L) {
                value = 40;
                p++;
            } else if (*(p+1) == C_C) {
                value = 90;
                p++;
            } else {
                value = C_X_V;
            }
            break;
        case C_L:
            value = C_L_V;
            break;
        case C_C:
        
            if (*(p+1) == C_D) {
                value = 400;
                p++;
            } else if (*(p+1) == C_M) {
                value = 900;
                p++;
            } else {
                value = C_C_V;
            }
            break;
        case C_D:
            value = C_D_V;
            break;
        case C_M:
            value = C_M_V;
            break;
        default:
            break;
        }
        sum += value;
        p++;
    }
    return sum;
}