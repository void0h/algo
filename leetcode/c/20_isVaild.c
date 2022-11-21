#include <string.h>

typedef struct stack {
    char *data;
    unsigned int stackSize;
    unsigned int count;
}stack_t;

stack_t *stack_create(int stackSize)
{
    stack_t *stack;

    if (stackSize == 0)
        return NULL;

    stack = (stack_t *)malloc(sizeof(stack_t));
    if (stack == NULL)
        return NULL;
    stack->count = 0;
    stack->stackSize = stackSize;
    stack->data = (char *)malloc(stackSize);
    if (stack->data == NULL) {
        free(stack);
        stack = NULL;
    }
    return stack;
}

void stack_destroy(stack_t *stack)
{
    if (stack == NULL)
        return;
    if (stack->data)
        free(stack->data);
    free(stack);
    stack = NULL;
}

bool stack_is_full(stack_t *stack)
{
    if (stack->count == stack->stackSize)
        return true;
    return false;
}

bool stack_is_empty(stack_t *stack)
{
    if (stack->count == 0)
        return true;
    return false;
}

bool stack_push(stack_t *stack, char data)
{
    if (stack == NULL || stack_is_full(stack))
        return false;
    
    stack->data[stack->count] = data;
    stack->count++;
    return true;
}

bool stack_pop(stack_t *stack, char *data)
{
    if (stack == NULL || stack_is_empty(stack))
        return false;
    *data = stack->data[stack->count - 1];
    stack->count--;
    return true;
}
// 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
// 内存消耗：5.5 MB, 在所有 C 提交中击败了71.46%的用户
bool isValid(char * s){
    char *p = s;
    int len;
    stack_t *stack;
    char data;
    bool state = true;

    len = strlen(s);
    stack = stack_create(len);

    while (*p != '\0') {
        if (*p == '(' || *p == '[' || *p == '{') {
            stack_push(stack, *p);
        } else {
            if (stack_pop(stack, &data) == false) {
                state = false;
                break;
            }
            if (*p == ')' && data != '(') {
                state = false;
                break;
            } else if (*p == ']' && data != '[') {
                state = false;
                break;
            } else if (*p == '}' && data != '{') {
                state = false;
                break;
            }
        }
        p++;
    }
    if (!stack_is_empty(stack))
        state = false;
    stack_destroy(stack);
    return state;
}
