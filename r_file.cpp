#include"a.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
extern void InsertBST(BSTree &T,int e,char *a,float b,char c);
extern BSTree SearchBST(BSTree T,int zid);
extern void huiyuanxinxi();

char x2[10000][50];//����˻�������
BSTree q;//q�ǻ�Ա�˻��Ķ�����
char x5[10000][30];//������Ѽ�Ŀ���е�������Ŀ
float x6[10000];//������Ѽ�Ŀ���е�������Ŀ�۸�
int m;//�˻���Ϣ��Ŀͻ�����
int c_number;//���Ѽ�Ŀ���е�������Ŀ����

int num_file(char *filename)//��ȡ�ļ����м�������
{
	FILE *fp=fopen(filename,"r");
	if(!fp)
	{
		printf("��ȡ�ļ�����!");
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

struct BSTnode* open_huiyuanxinxi()//��ȡ�˻���Ϣ��Ļ�Ա��Ϣ��������������
{
	q=NULL;
	FILE *fp=fopen("�˻���Ϣ.txt","rt+");
	m=num_file("�˻���Ϣ.txt");
	int x1[10000];//��Ż�Ա���˺�
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

void open_xianmujiamubiao()//��ȡ������Ŀ��Ŀ�����Ϣ�����뵽x5��x6����
{
	FILE *fj=fopen("������Ŀ��Ŀ��.txt","rt+");
	c_number=num_file("������Ŀ��Ŀ��.txt");
	for(int j=0;j<c_number;j++)
	{
		fscanf(fj,"%s ",x5[j]);
		fscanf(fj,"%f\n",&x6[j]);
	}
	fclose(fj);
}

struct BSTnode* open_xiaofeixinxi()//��ȡ������Ϣ���е���Ϣ���ҽ�������Ϣ��ֵ����ص��˺�
{
	FILE *fx=fopen("������Ϣ.txt","rt+");
	int x_number;
	x_number=num_file("������Ϣ.txt");
	int x7[10000];//��������˵Ļ�Ա�˺�
	char x8[10000][20];//�������ʱ��
	char x9[10000][30];//���ÿ����Ա��������Ŀ
	float x10[10000];//���ÿ��������Ŀ�����Ѽ۸�
	char cunkuan[10]="���";
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

		if(strcmp(cunkuan,x9[y])==0)//����Ǵ��Ͱ������ϴ����
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
