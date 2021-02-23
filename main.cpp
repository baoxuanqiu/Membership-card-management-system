#include"a.h"
#include <iostream>
#include<stdio.h>
#include<string.h>
extern struct BSTnode* open_huiyuanxinxi();
extern void InsertBST(BSTree &T,int e,char *a,float b,char c);
extern void InorderTraverse(BSTree T);
extern int num_file(char *filename);
extern int nodecount(BSTree T);
extern void huiyuanxinxi();
extern int kaihu(char *kname);
extern void open_xianmujiamubiao();
extern struct BSTnode* open_xiaofeixinxi();
extern void show_xiaofeijiamu();
extern int xukuan();
extern int xiaofei();
extern int show_balance();
extern int show_con_record();//显示消费记录
extern int xiaohu(int xiao_id);//销户

int main()
{
	char kname[100][20];
	int shuzi;
	int js=0;//对开户次数的计数
	int xh;//销户账号
	open_huiyuanxinxi();//打开账户信息表
	open_xiaofeixinxi();//打开消费信息表，对表中已有的的账户信息的余额对应其消费项目进行修改
	open_xianmujiamubiao();//打开消费项目价目表
	printf("请输入你要进行的操作的数字。\n0:退出操作\n1:开户\n2:销户\n3:续款\n4:显示消费项目价目表\n5:消费\n6:显示所有会员账号信息\n7:显示账户余额\n8:显示账户消费记录\n");
	scanf("%d",&shuzi);
	while(shuzi)
	{
		switch(shuzi)
		{
			case 1:
				  	printf("请输入你的名字!");
					scanf("%s",kname[js]);
					kaihu(kname[js]);//开户
					js++;
					break;
			case 2:
					printf("请输入要销户的账号!");
					scanf("%d",&xh);
					xiaohu(xh);break;//销户
			case 3:xukuan();break;//续款
			case 4:show_xiaofeijiamu();break;//显示消费项目价目表
			case 5:xiaofei();break;
			case 6:huiyuanxinxi();break;//显示会员信息
			case 7:show_balance();break;//显示账户余额
			case 8:show_con_record();break;//显示消费记录
		}
		printf("\n\n请输入你要进行的操作的数字。\n0:退出操作\n1:开户\n2:销户\n3:续款\n4:显示消费项目价目表\n5:消费\n6:显示所有会员账号信息\n7:显示账户余额\n8:显示账户消费记录\n");
		scanf("%d",&shuzi);
	}


	return 0;
}
