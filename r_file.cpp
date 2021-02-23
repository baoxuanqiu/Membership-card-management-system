#include"a.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
extern void InsertBST(BSTree &T,int e,char *a,float b,char c);
extern BSTree SearchBST(BSTree T,int zid);
extern void huiyuanxinxi();

char x2[10000][50];//存放账户的名字
BSTree q;//q是会员账户的二叉树
char x5[10000][30];//存放消费价目表中的消费项目
float x6[10000];//存放消费价目表中的消费项目价格
int m;//账户信息表的客户数量
int c_number;//消费价目表中的消费项目数量

int num_file(char *filename)//读取文件中有几行数据
{
	FILE *fp=fopen(filename,"r");
	if(!fp)
	{
		printf("读取文件出错!");
		return -1;
	}
	char buf[10000]={0};
	char *p=NULL;
	int num=0;
	while((p=fgets(buf,sizeof(buf)-1,fp))!=NULL)
	{
		if(buf[strlen(buf)-1]=='\n')
			num++;
	}
	fclose(fp);
	return num+1;
}

struct BSTnode* open_huiyuanxinxi()//读取账户信息表的会员信息并创建二叉链表
{
	q=NULL;
	FILE *fp=fopen("账户信息.txt","rt+");
	m=num_file("账户信息.txt");
	int x1[10000];//存放会员的账号
	float x3[10000];
	char x4[10000];
	for(int i=0;i<m;i++)
	{
		fscanf(fp,"%d ",&x1[i]);
		fscanf(fp,"%s ",x2[i]);
		fscanf(fp,"%f ",&x3[i]);
		fscanf(fp,"%c",&x4[i]);
		InsertBST(q,x1[i],x2[i],x3[i],x4[i]);
	}
	fclose(fp);
	return q;
}

void open_xianmujiamubiao()//读取消费项目价目表的信息并存入到x5，x6数组
{
	FILE *fj=fopen("消费项目价目表.txt","rt+");
	c_number=num_file("消费项目价目表.txt");
	for(int j=0;j<c_number;j++)
	{
		fscanf(fj,"%s ",x5[j]);
		fscanf(fj,"%f\n",&x6[j]);
	}
	fclose(fj);
}

struct BSTnode* open_xiaofeixinxi()//读取消费信息表中的信息并且将消费信息赋值给相关的账号
{
	FILE *fx=fopen("消费信息.txt","rt+");
	int x_number;
	x_number=num_file("消费信息.txt");
	int x7[10000];//存放消费了的会员账号
	char x8[10000][20];//存放消费时间
	char x9[10000][30];//存放每个会员的消费项目
	float x10[10000];//存放每个消费项目的消费价格
	char cunkuan[10]="存款";
	for(int x=0;x<x_number;x++)
	{
		fscanf(fx,"%d ",&x7[x]);
		fscanf(fx,"%s ",x8[x]);
		fscanf(fx,"%s ",x9[x]);
		fscanf(fx,"%f\n",&x10[x]);
	}
	for(int y=0;y<x_number;y++)
	{
		BSTree p;
		p=SearchBST(q,x7[y]);
		p_node_con head;
		head=(struct node_con *)malloc(sizeof(struct node_con));
		head->time=x8[y];
		head->consume=x9[y];
		head->price=x10[y];

		if((p->first_node_con)==NULL)
		{
			p->first_node_con=head;
			p->first_node_con->next=NULL;
		}
		else
		{
			head->next=p->first_node_con;
			p->first_node_con=head;
		}

		if(strcmp(cunkuan,x9[y])==0)//如果是存款，就把余额加上存款金额
		{
			p->balance+=x10[y];
		}
		else
		{
			p->balance-=x10[y];
		}
	}
	fclose(fx);
	return q;
}
