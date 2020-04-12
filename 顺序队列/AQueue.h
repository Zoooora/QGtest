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
//ѭ�����нṹ
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
    free(Q);
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
    return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//�޸Ľӿ�����
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *  @name        : void APrint(void *q)//���䣺�޸Ľӿ����£�ԭ�ӿڲ���Ϊ���
 *    @description : ��������
 *    @param         q ָ��q
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


