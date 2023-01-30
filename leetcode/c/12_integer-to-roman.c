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
// 5.8 MB
// , 在所有 C 提交中击败了
// 54.32%
// 的用户
// 通过测试用例：
// 3999 / 3999
char * intToRoman(int num){
    char *str = (char *)calloc(20, 1);
    int index = 0;

    while (num) {
        if (num >= 1000) {
            str[index++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            str[index++] = 'C';
            str[index++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            str[index++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            str[index++] = 'C';
            str[index++] = 'D';
            num -= 400;
        }  else if (num >= 100) {
            str[index++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            str[index++] = 'X';
            str[index++] = 'C';
            num -= 90;
        }  else if (num >= 50) {
            str[index++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            str[index++] = 'X';
            str[index++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            str[index++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            str[index++] = 'I';
            str[index++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            str[index++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            str[index++] = 'I';
            str[index++] = 'V';
            num -= 4;
        } else if (num >= 1) {
            str[index++] = 'I';
            num -= 1;
        }  
    }
    return str;
}