#ifndef A_H_INCLUDED
#define A_H_INCLUDED
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string>
using namespace std;

typedef struct node_con//消费记录结点
{
	char *time;//消费时间
    char *consume;//消费项目
    float price;//消费价格
	struct node_con *next;//指向下一个消费记录结点
}node_con,*p_node_con;

typedef struct BSTnode
{
    int ID;//账号
    char *Name;//姓名
    float balance;//余额
    char level;//会员级别
    struct node_con *first_node_con;//指向账户的第一个消费记录结点
    struct BSTnode *lchild,*rchild;//左右孩子指针
}BSTnode,*BSTree;



#endif // A_H_INCLUDED
