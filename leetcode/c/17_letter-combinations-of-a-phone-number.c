
/*****************************看过题解后***********************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char  *num_map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char **combinations = NULL;
int combinations_size = 0;
char *combination = NULL;
int combination_size = 0;

void backtracking(char *digits, int digits_len, int index)
{
    int letter_size;
    char *letter;

    if (index == digits_len) {
        char *tmp = (char *)malloc(digits_len+1);
        strcpy(tmp, combination);
        combinations[combinations_size++] = tmp;
        return;
    }
    letter = num_map[digits[index]-'0'];
    letter_size = strlen(letter);
    for (int i = 0; i < letter_size; i++) {
        combination[combination_size++] = letter[i];
        combination[combination_size] = '\0';
        backtracking(digits, digits_len, index+1);
        combination[--combination_size] = '\0';
    }
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
// 6 MB
// , 在所有 C 提交中击败了
// 17.42%
// 的用户
// 通过测试用例：
// 25 / 25
char ** letterCombinations(char * digits, int* returnSize){
    int digits_len;
    
    *returnSize = 0;
    if (digits == NULL || strlen(digits) == 0)
        return NULL;
    combinations_size = 0;
    combination_size = 0;
    digits_len = strlen(digits);
    int num = 1;
    for (int i = 0; i < digits_len; i++) num *= 4;
    combinations = (char **)malloc(sizeof(char **)*pow(4, digits_len));
    combination = (char *)malloc(digits_len+1);

    backtracking(digits, digits_len, 0);
    *returnSize = combinations_size;

    return combinations;
}
