#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;


typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct BiTNode {
    TElemType data;     // 数据域
    BiTNode* lchild, * rchild;  // 左、右孩子指针
} BiTNode, * BiTree;   // 二叉链表


typedef enum Status{
	SUCCESS = 1,
	ERROR = 0,
}Status;


    /**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
    Status InitBiTree(BiTree T) {
        /*T->lchild == nullptr;
        T->rchild == nullptr;*/
        return SUCCESS;
    }


    /**
     *  @name        : Status DestroyBiTree(BiTree T);
     *  @description : 摧毁二叉树T
     *  @param       : 二叉树根结点T
     */
    Status DestroyBiTree(BiTree T) {
        if (T->lchild != nullptr) {
            DestroyBiTree(T->lchild);
        }
        if (T->rchild != nullptr) {
            DestroyBiTree(T->rchild);
        }
        free(T);
        return SUCCESS;
    }


    /**
     *  @name        : Status CreateBiTree(BiTree T, char* definition);
     *  @description : 构造二叉树T
     *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
     */
    int CreateBiTree(BiTree T, TElemType definition[], int i, BiTree* temp) {
        int len = strlen(definition);
        /*if (i == len) {
            return SUCCESS;
        }
        if (definition[i] == '#') {
            T = nullptr;
        }
        else {
            T = (BiTNode*)malloc(sizeof(BiTNode));
            T->data = definition[i++];
            CreateBiTree(T->lchild, definition);
            CreateBiTree(T->rchild, definition);
        }
        return SUCCESS;*/
        for (; i < len; i++) {
            if (definition[i] == '#') {
                T = nullptr;
            }
            else {
                T = (BiTNode*)malloc(sizeof(BiTNode));
                if (i == 0) {
                    temp = &T;
                }
                T->data = definition[i];
                i = CreateBiTree(T->lchild, definition, i + 1, temp);
                i = CreateBiTree(T->rchild, definition, i + 1, temp);
            }
        }
        return i;
    }


    /**
     *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
     *  @description : 先序遍历二叉树T
     *  @param       : 二叉树根结点T, 对结点的操作函数visit
     */
    Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
        if (T != nullptr) {
            visit(T->data);
            PreOrderTraverse(T->lchild, visit);
            PreOrderTraverse(T->rchild, visit);
        }
        return SUCCESS;
    }


    /**
     *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
     *  @description : 中序遍历二叉树T
     *  @param       : 二叉树根结点T, 对结点的操作函数visit
     */
    Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
        if (T != nullptr) {
            InOrderTraverse(T->lchild, visit);
            visit(T->data);
            InOrderTraverse(T->rchild, visit);
        }
        return SUCCESS;
    }


    /**
     *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
     *  @description : 后序遍历二叉树T
     *  @param       : 二叉树根结点T, 对结点的操作函数visit
     */
    Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
        if (T != nullptr) {
            PostOrderTraverse(T->lchild, visit);
            PostOrderTraverse(T->rchild, visit);
            visit(T->data);
        }
        return SUCCESS;
    }


    /**
     *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
     *  @description : 层序遍历二叉树T
     *  @param       : 二叉树根结点T, 对结点的操作函数visit
     */
    Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
        queue<BiTNode*> q;
        if (T != nullptr) {
            q.push(T);
        }
        while (q.empty() == false) {
            visit(T->data);
            if (q.front()->lchild != nullptr) {
                q.push(q.front()->lchild);
            }
            if (q.front()->rchild != nullptr) {
                q.push(q.front()->rchild);
            }
            q.pop();
        }
        return SUCCESS;
    }


    /**
     *  @name        : int Value(BiTree T);
     *  @description : 对构造出的前缀表达式二叉树求值
     *  @param       : 二叉树根结点T
     *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
     *                 可根据需要自行增加操作.
     */
    int Value(BiTree T);


#endif // BINARYTREE_H_INCLUDED
