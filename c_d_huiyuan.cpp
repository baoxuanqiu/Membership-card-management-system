#include"a.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include <stdlib.h>
extern void InsertBST(BSTree &T,int e,char *a,float b,char c);
extern void InorderTraverse(BSTree T);
extern BSTree SearchBST(BSTree T,int zid);
extern int nodecount(BSTree T);

extern 	char x2[10000][50];//存放账户的名字
extern int m;//账户信息表的客户数量
extern BSTree q;//q是会员账户的二叉树
extern char x5[10000][30];//存放消费价目表中的消费项目
extern float x6[10000];//存放消费价目表中的消费项目价格
extern int c_number;//消费价目表中的消费项目数量

time_t t;
struct tm * lt;
char r1[20],r2[10],r3[10],r4[2]=".",r5[20];

void huiyuanxinxi()//显示所有的账号信息
{
	printf("-----------------------------\n");
	printf("账号\t姓名\t\t余额\t\t会员级别\n");
	InorderTraverse(q);
	printf("-----------------------------\n");
}

int kaihu(char *kname)//开户
{
	int id_num,km;
	float bal;
	char le;
	int jiedian_num;
	BSTree kh_tree;
	jiedian_num=nodecount(q);
	km=95000+jiedian_num+1;
	for(id_num=95001;id_num<=km;id_num++)//新开户的会员会在结点数+1个会员账号中选择一个空的结点账号赋给他
	{
		kh_tree=SearchBST(q,id_num);
		if(!kh_tree)
			break;
	}
	bal=0.0;
	le='S';
	for(int i=95001;i<=km;i++)
	{
		kh_tree=SearchBST(q,i);
		if(kh_tree)
		{
			if(strcmp(kname,kh_tree->Name)==0)
			{
				printf("该账户已经存在!\n");
				return -1;
			}
		}
	}
	InsertBST(q,id_num,kname,bal,le);
	printf("%s,恭喜你开户成功!你的账号是%d\n",kname,id_num);
	return 0;
}

void show_xiaofeijiamu()//列出消费项目所对应的价格
{
	printf("\t*************************************\n");
	printf("\t消费项目\t\t价格\n");
	for(int num=0;num<c_number;num++)
	{
		printf("\t%s\t\t%f\n",x5[num],x6[num]);
	}
	printf("\t*************************************\n");
}


int xukuan()//续款
{
	BSTree xk_zh;

	//续款后改变余额
	int zhanghao;
	float m;
	printf("请输入要徐款的账号!");
	scanf("%d",&zhanghao);
	xk_zh=SearchBST(q,zhanghao);
	if(!xk_zh)
	{
		printf("此账号不存在!\n");
		return -1;
	}
	printf("亲爱的%s,你当前的账户余额为%f。请输入你要存款的金额\n",xk_zh->Name,xk_zh->balance);
	scanf("%f",&m);
	xk_zh->balance+=m;

	//提取系统时间
	time(&t);
	lt=gmtime(&t);
	itoa(lt->tm_year+1900,r1,10);
	itoa(lt->tm_mon+1,r2,10);
	itoa(lt->tm_mday,r3,10);
	strcpy(r5,r1);//将r1的值赋给r5，用于下面的显示语句
	strcat(r1,r4);
	strcat(r1,r2);
	strcat(r1,r4);
	strcat(r1,r3);

	//将续款消费记录记入消费结点
	p_node_con cunkuan;
	cunkuan=(struct node_con *)malloc(sizeof(struct node_con));
	cunkuan->time=r1;
	cunkuan->consume="存款";
	cunkuan->price=m;
	if((xk_zh->first_node_con)==NULL)
	{
		xk_zh->first_node_con=cunkuan;
		xk_zh->first_node_con->next=NULL;
	}
	else
	{
		cunkuan->next=xk_zh->first_node_con;
		xk_zh->first_node_con=cunkuan;
	}

	//显示消费记录
	printf("\n++++++++++++++++++++++++++++\n");
	printf("亲爱的%s,你在%s年%s月%s日存款%f。你目前的余额为%f,祝你消费愉快!\n",xk_zh->Name,r5,r2,r3,m,xk_zh->balance);
	printf("++++++++++++++++++++++++++++\n");
	return 0;
}


int xiaofei()//用户进行消费并且生成消费记录
{
	int z_hao;//账号
	int xf;//指向消费项目的序号
	BSTree xf_zh;
	char xf_xm[20];//存放消费项目
	float jiage;

	printf("请输入要消费的账号!");
	scanf("%d",&z_hao);
	xf_zh=SearchBST(q,z_hao);
	if(!xf_zh)
	{
		printf("此账号不存在!\n");
		return -1;
	}
	printf("请输入要消费的项目!\n");
	scanf("%s",xf_xm);
	for(xf=0;xf<c_number;xf++)
	{
		if(strcmp(xf_xm,x5[xf])==0)
			break;
	}
	if(xf>=c_number)
	{
		printf("商店里没有该商品!\n");
		return -1;
	}
	if(xf<c_number)
	{
		switch(xf_zh->level)
		{
		case 'S':jiage=x6[xf];break;//会员级别是s，不享受优惠
		case 'M':jiage=0.8*x6[xf];break;//会员级别为m，享受8折优惠
		case 'L':jiage=0.7*x6[xf];break;//会员级别为l,享受7折优惠
		}
		xf_zh->balance-=jiage;
		if(xf_zh->balance<0.0)
		{
			printf("你的金额不够!购买失败\n");
			xf_zh->balance+=jiage;
			return -1;
		}
		printf("消费成功!");

		time(&t);
		lt=gmtime(&t);
		itoa(lt->tm_year+1900,r1,10);
		itoa(lt->tm_mon+1,r2,10);
		itoa(lt->tm_mday,r3,10);
		strcpy(r5,r1);//将r1的值赋给r5，用于下面的显示语句
		strcat(r1,r4);
		strcat(r1,r2);
		strcat(r1,r4);
		strcat(r1,r3);

		p_node_con xiaofei;
		xiaofei=(struct node_con *)malloc(sizeof(struct node_con));
		xiaofei->time=r1;
		xiaofei->consume=x5[xf];
		xiaofei->price=jiage;
		if((xf_zh->first_node_con)==NULL)
		{
			xf_zh->first_node_con=xiaofei;
			xf_zh->first_node_con->next=NULL;
		}
		else
		{
			xiaofei->next=xf_zh->first_node_con;
			xf_zh->first_node_con=xiaofei;
		}

			//显示消费记录
		if(xf_zh->level=='S')
		{
			printf("\n++++++++++++++++++++++++++++\n");
			printf("亲爱的%s,你在%s年%s月%s日购买了%s，由于你的会员级别为S,所以不享受打折优惠，该商品消费金额为%f，祝你消费愉快!\n",xf_zh->Name,r5,r2,r3,x5[xf],jiage);
			printf("++++++++++++++++++++++++++++\n");
			return 0;
		}
		printf("\n++++++++++++++++++++++++++++\n");
		printf("亲爱的%s,你在%s年%s月%s日购买了%s，你的会员级别为%c,打折后商品金额为%f，祝你消费愉快!\n",xf_zh->Name,r5,r2,r3,x5[xf],xf_zh->level,jiage);//这里显示的金额是打折后的金额
		printf("++++++++++++++++++++++++++++\n");
	}

	return 0;
}

int show_balance()//显示账户余额
{
	int bal_id;
	BSTree s_bal;
	float bal_num;
	printf("请输入要查询余额的账号!");
	scanf("%d",&bal_id);
	s_bal=SearchBST(q,bal_id);
	if(!s_bal)
	{
		printf("该账户不存在!");
		return -1;
	}
	bal_num=s_bal->balance;
	printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("亲爱的%s,你的账户余额为%f,祝你消费愉快!\n",s_bal->Name,bal_num);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	return 0;
}

int show_con_record()//显示消费记录
{
	int con_id;
	BSTree s_con;
	p_node_con con;

	printf("请输入要查询消费记录的账号!");
	scanf("%d",&con_id);
	s_con=SearchBST(q,con_id);
	if(!s_con)
	{
		printf("该账户不存在!");
		return -1;
	}
	con=s_con->first_node_con;
	if(con==NULL)
	{
		printf("亲爱的%s,至今为止你还没有消费过喔。\n",s_con->Name);
		return -1;
	}
	printf("=================================\n");
	printf("亲爱的%s,你的消费记录为:\n",s_con->Name);
	while(con!=NULL)
	{
		printf("%s\t",con->time);
		printf("%s\t",con->consume);
		printf("%f\n",con->price);
		con=con->next;
	}
	printf("=================================\n");
	return 0;
}

int xiaohu(int xiao_id)//销户
{
	BSTree p,p1,plchild,prchild,m=NULL;
	p=q;
	char name[20];

	p1=SearchBST(q,xiao_id);
	if(!p1)
	{
		printf("该账号用户不存在!销户失败\n");
		return -1;
	}
	if(p1->balance!=0.0)
	{
		printf("亲爱的%s,你的余额不为0，不能销户喔!\n",p1->Name);
		return -1;
	}

	while(p)
	{
		if(p->ID==xiao_id)//找到该账户
			break;
		m=p;//m是该账户的双亲
		if(p->ID>xiao_id)
			p=p->lchild;
		else p=p->rchild;
	}
	strcpy(name,p->Name);
	prchild=p;

	if((p->lchild)&&(p->rchild))//被删账户的左右孩子均不为空
	{
		plchild=p->lchild;
		while(plchild->rchild)
		{
			prchild=plchild;
			plchild=plchild->rchild;
		}
		p->balance=plchild->balance;
		p->ID=plchild->ID;
		p->level=plchild->level;
		p->Name=plchild->Name;
		p->first_node_con=plchild->first_node_con;
		if(prchild!=p)
			prchild->rchild=plchild->lchild;
		else
			prchild->lchild=plchild->lchild;
		delete plchild;
		return 0;
	}
	else if(!p->rchild)//被删账户没有右孩子的情况
		p=p->lchild;

	else if(!p->lchild)//被删账户没有左孩子的情况
		p=p->rchild;
	if(!m)//被删账户为根结点
		q=p;
	else if(prchild==m->lchild)
		m->lchild=p;
	else
		m->rchild=p;
	delete prchild;
	printf("账号%d，%s用户余额为0，销户成功!",xiao_id,name);

	return 0;
}
