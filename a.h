#ifndef A_H_INCLUDED
#define A_H_INCLUDED
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string>
using namespace std;

typedef struct node_con//���Ѽ�¼���
{
	char *time;//����ʱ��
    char *consume;//������Ŀ
    float price;//���Ѽ۸�
	struct node_con *next;//ָ����һ�����Ѽ�¼���
}node_con,*p_node_con;

typedef struct BSTnode
{
    int ID;//�˺�
    char *Name;//����
    float balance;//���
    char level;//��Ա����
    struct node_con *first_node_con;//ָ���˻��ĵ�һ�����Ѽ�¼���
    struct BSTnode *lchild,*rchild;//���Һ���ָ��
}BSTnode,*BSTree;



#endif // A_H_INCLUDED
