#include<stdio.h>
#include"a.h"
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void InsertBST(BSTree &T,int e,char *a,float b,char c)
{
    if(!T)
    {
        BSTree S;
		S=(struct BSTnode *)malloc(sizeof(struct BSTnode));
        S->ID=e;
		S->Name=a;
		S->balance=b;
		S->first_node_con=NULL;
		S->level=c;
        S->lchild=S->rchild=NULL;
        T=S;
    }
    else if(e<T->ID)
        InsertBST(T->lchild,e,a,b,c);
    else if(e>T->ID)
        InsertBST(T->rchild,e,a,b,c);
}

void InorderTraverse(BSTree T)//显示所有账户的账号，姓名，余额，会员级别
{
	if(T)
	{
		InorderTraverse(T->lchild);
		printf("%d\t",T->ID);
		printf("%s\t",T->Name);
		printf("%f\t",T->balance);
		printf("%c\n",T->level);
		InorderTraverse(T->rchild);
	}
}

int nodecount(BSTree T)
{
	int node;
	if(T==NULL)
		return 0;
	else
	{
		 node=nodecount(T->lchild)+nodecount(T->rchild)+1;
		 return node;
	}
}

BSTree SearchBST(BSTree T,int zid)
{
	if((!T)||zid==T->ID)
		return T;
	else if(zid<T->ID)
		return SearchBST(T->lchild,zid);
	else return SearchBST(T->rchild,zid);
}

