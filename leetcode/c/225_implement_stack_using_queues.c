

typedef struct {
    int *data;
    unsigned int queueSize;
    int head;
    int tail;
} MyQueue;

MyQueue *myQueueCreate(int queueSize)
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    if (queue == NULL)
        return NULL;
    queue->data = (int *)malloc(sizeof(int)*queueSize);
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }
    queue->head = 0;
    queue->tail = 0;
    queue->queueSize = queueSize;

    return queue;
}

void myQueueFree(MyQueue *obj)
{
    if (obj) {
        free(obj->data);
        free(obj);
        obj = NULL;
    }
}

bool myQueueIsFull(MyQueue *obj)
{
    if (obj->head == (obj->tail+1)%obj->queueSize)
        return true;
    return false;
}

bool myQueueIsEmpty(MyQueue *obj)
{
    if (obj->head == obj->tail)
        return true;
    return false;
}

bool myQueueEnqueue(MyQueue *obj, int data)
{
    if (myQueueIsFull(obj))
        return false;
    obj->data[obj->tail] = data;
    obj->tail = (obj->tail + 1)%obj->queueSize;
    return true;
}

bool myQueueDequeue(MyQueue *obj, int *data)
{
    if (myQueueIsEmpty(obj))
        return false;
    *data = obj->data[obj->head];
    obj->head = (obj->head+1)%obj->queueSize;
    
    return true;
}

bool myQueueDequeueNoDel(MyQueue *obj, int *data)
{
    if (myQueueIsEmpty(obj))
        return false;
    *data = obj->data[obj->head];
    return true;
}

typedef struct {
    MyQueue *queue1;
    MyQueue *queue2;
} MyStack;

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->queue1 = myQueueCreate(10);
    stack->queue2 = myQueueCreate(10);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    int data;
    if (myQueueIsEmpty(obj->queue1)) {
        myQueueEnqueue(obj->queue1, x);
        while (!myQueueIsEmpty(obj->queue2)) {
            myQueueDequeue(obj->queue2, &data);
            myQueueEnqueue(obj->queue1, data);
        }
    } else {
        myQueueEnqueue(obj->queue2, x);
        while (!myQueueIsEmpty(obj->queue1)) {
            myQueueDequeue(obj->queue1, &data);
            myQueueEnqueue(obj->queue2, data);
        }
    }
}

int myStackPop(MyStack* obj) {
    int data = 0;
    if (!myQueueIsEmpty(obj->queue1)) {
        myQueueDequeue(obj->queue1, &data);
    } else if (!myQueueIsEmpty(obj->queue2)) {
        myQueueDequeue(obj->queue2, &data);
    }
    return data;
}

int myStackTop(MyStack* obj) {
    int data = 1;
    if (!myQueueIsEmpty(obj->queue1)) {
        myQueueDequeueNoDel(obj->queue1, &data);
    } else if (!myQueueIsEmpty(obj->queue2)) {
        myQueueDequeueNoDel(obj->queue2, &data);
    }
    return data;
}

bool myStackEmpty(MyStack* obj) {
    if (myQueueIsEmpty(obj->queue1) && myQueueIsEmpty(obj->queue2))
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

// 执行用时：
// 0 ms
// , 在所有 C 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.7 MB
// , 在所有 C 提交中击败了
// 58.84%
// 的用户