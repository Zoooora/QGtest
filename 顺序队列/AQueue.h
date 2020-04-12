#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//循环队列结构
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
    free(Q);
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
    if (Q->length == MAXQUEUE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
    if (Q->length == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
    if (Q->length == 0) {
        return FALSE;
    }
    else {
        memcpy(e, &Q->data[Q->front], sizeof(Q->data[Q->front]));
        return TRUE;
    }
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
    return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue* Q, void* data) {
    if (Q->length == MAXQUEUE) {
        return FALSE;
    }
    memcpy(&Q->data[Q->rear], data, sizeof(data));
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->length += 1;
    return TRUE;
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q) {
    if (Q->length == 0) {
        return FALSE;
    }
    else {
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->length -= 1;
        return TRUE;
    }
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//修改接口如下
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, int size, void (*foo)(void* q, int Eletype)) {
    int temp = Q->front;
    //foo = APrint;
    if (Q->length == 0) {
        return FALSE;
    }
    else {
        for (; temp < Q->rear; temp = (temp + 1) % MAXQUEUE) {
            foo(&Q->data[temp], size);
        }
    }
    return TRUE;
}


/**
 *  @name        : void APrint(void *q)//补充：修改接口如下，原接口参数为左侧
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void* q, int Eletype) {
    void* ElemAddr = (char*)q;
    if (Eletype == 1) {
        printf("%c\n", *(char*)ElemAddr);
    }
    else if (Eletype == 4) {
        printf("%d\n", *(int*)ElemAddr);
    }
}


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED


