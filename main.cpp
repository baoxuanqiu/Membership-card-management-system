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
extern int show_con_record();//��ʾ���Ѽ�¼
extern int xiaohu(int xiao_id);//����

int main()
{
	char kname[100][20];
	int shuzi;
	int js=0;//�Կ��������ļ���
	int xh;//�����˺�
	open_huiyuanxinxi();//���˻���Ϣ��
	open_xiaofeixinxi();//��������Ϣ���Ա������еĵ��˻���Ϣ������Ӧ��������Ŀ�����޸�
	open_xianmujiamubiao();//��������Ŀ��Ŀ��
	printf("��������Ҫ���еĲ��������֡�\n0:�˳�����\n1:����\n2:����\n3:����\n4:��ʾ������Ŀ��Ŀ��\n5:����\n6:��ʾ���л�Ա�˺���Ϣ\n7:��ʾ�˻����\n8:��ʾ�˻����Ѽ�¼\n");
	scanf("%d",&shuzi);
	while(shuzi)
	{
		switch(shuzi)
		{
			case 1:
				  	printf("�������������!");
					scanf("%s",kname[js]);
					kaihu(kname[js]);//����
					js++;
					break;
			case 2:
					printf("������Ҫ�������˺�!");
					scanf("%d",&xh);
					xiaohu(xh);break;//����
			case 3:xukuan();break;//����
			case 4:show_xiaofeijiamu();break;//��ʾ������Ŀ��Ŀ��
			case 5:xiaofei();break;
			case 6:huiyuanxinxi();break;//��ʾ��Ա��Ϣ
			case 7:show_balance();break;//��ʾ�˻����
			case 8:show_con_record();break;//��ʾ���Ѽ�¼
		}
		printf("\n\n��������Ҫ���еĲ��������֡�\n0:�˳�����\n1:����\n2:����\n3:����\n4:��ʾ������Ŀ��Ŀ��\n5:����\n6:��ʾ���л�Ա�˺���Ϣ\n7:��ʾ�˻����\n8:��ʾ�˻����Ѽ�¼\n");
		scanf("%d",&shuzi);
	}


	return 0;
}
