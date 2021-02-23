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

extern 	char x2[10000][50];//����˻�������
extern int m;//�˻���Ϣ��Ŀͻ�����
extern BSTree q;//q�ǻ�Ա�˻��Ķ�����
extern char x5[10000][30];//������Ѽ�Ŀ���е�������Ŀ
extern float x6[10000];//������Ѽ�Ŀ���е�������Ŀ�۸�
extern int c_number;//���Ѽ�Ŀ���е�������Ŀ����

time_t t;
struct tm * lt;
char r1[20],r2[10],r3[10],r4[2]=".",r5[20];

void huiyuanxinxi()//��ʾ���е��˺���Ϣ
{
	printf("-----------------------------\n");
	printf("�˺�\t����\t\t���\t\t��Ա����\n");
	InorderTraverse(q);
	printf("-----------------------------\n");
}

int kaihu(char *kname)//����
{
	int id_num,km;
	float bal;
	char le;
	int jiedian_num;
	BSTree kh_tree;
	jiedian_num=nodecount(q);
	km=95000+jiedian_num+1;
	for(id_num=95001;id_num<=km;id_num++)//�¿����Ļ�Ա���ڽ����+1����Ա�˺���ѡ��һ���յĽ���˺Ÿ�����
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
				printf("���˻��Ѿ�����!\n");
				return -1;
			}
		}
	}
	InsertBST(q,id_num,kname,bal,le);
	printf("%s,��ϲ�㿪���ɹ�!����˺���%d\n",kname,id_num);
	return 0;
}

void show_xiaofeijiamu()//�г�������Ŀ����Ӧ�ļ۸�
{
	printf("\t*************************************\n");
	printf("\t������Ŀ\t\t�۸�\n");
	for(int num=0;num<c_number;num++)
	{
		printf("\t%s\t\t%f\n",x5[num],x6[num]);
	}
	printf("\t*************************************\n");
}


int xukuan()//����
{
	BSTree xk_zh;

	//�����ı����
	int zhanghao;
	float m;
	printf("������Ҫ�����˺�!");
	scanf("%d",&zhanghao);
	xk_zh=SearchBST(q,zhanghao);
	if(!xk_zh)
	{
		printf("���˺Ų�����!\n");
		return -1;
	}
	printf("�װ���%s,�㵱ǰ���˻����Ϊ%f����������Ҫ���Ľ��\n",xk_zh->Name,xk_zh->balance);
	scanf("%f",&m);
	xk_zh->balance+=m;

	//��ȡϵͳʱ��
	time(&t);
	lt=gmtime(&t);
	itoa(lt->tm_year+1900,r1,10);
	itoa(lt->tm_mon+1,r2,10);
	itoa(lt->tm_mday,r3,10);
	strcpy(r5,r1);//��r1��ֵ����r5�������������ʾ���
	strcat(r1,r4);
	strcat(r1,r2);
	strcat(r1,r4);
	strcat(r1,r3);

	//���������Ѽ�¼�������ѽ��
	p_node_con cunkuan;
	cunkuan=(struct node_con *)malloc(sizeof(struct node_con));
	cunkuan->time=r1;
	cunkuan->consume="���";
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

	//��ʾ���Ѽ�¼
	printf("\n++++++++++++++++++++++++++++\n");
	printf("�װ���%s,����%s��%s��%s�մ��%f����Ŀǰ�����Ϊ%f,ף���������!\n",xk_zh->Name,r5,r2,r3,m,xk_zh->balance);
	printf("++++++++++++++++++++++++++++\n");
	return 0;
}


int xiaofei()//�û��������Ѳ����������Ѽ�¼
{
	int z_hao;//�˺�
	int xf;//ָ��������Ŀ�����
	BSTree xf_zh;
	char xf_xm[20];//���������Ŀ
	float jiage;

	printf("������Ҫ���ѵ��˺�!");
	scanf("%d",&z_hao);
	xf_zh=SearchBST(q,z_hao);
	if(!xf_zh)
	{
		printf("���˺Ų�����!\n");
		return -1;
	}
	printf("������Ҫ���ѵ���Ŀ!\n");
	scanf("%s",xf_xm);
	for(xf=0;xf<c_number;xf++)
	{
		if(strcmp(xf_xm,x5[xf])==0)
			break;
	}
	if(xf>=c_number)
	{
		printf("�̵���û�и���Ʒ!\n");
		return -1;
	}
	if(xf<c_number)
	{
		switch(xf_zh->level)
		{
		case 'S':jiage=x6[xf];break;//��Ա������s���������Ż�
		case 'M':jiage=0.8*x6[xf];break;//��Ա����Ϊm������8���Ż�
		case 'L':jiage=0.7*x6[xf];break;//��Ա����Ϊl,����7���Ż�
		}
		xf_zh->balance-=jiage;
		if(xf_zh->balance<0.0)
		{
			printf("��Ľ���!����ʧ��\n");
			xf_zh->balance+=jiage;
			return -1;
		}
		printf("���ѳɹ�!");

		time(&t);
		lt=gmtime(&t);
		itoa(lt->tm_year+1900,r1,10);
		itoa(lt->tm_mon+1,r2,10);
		itoa(lt->tm_mday,r3,10);
		strcpy(r5,r1);//��r1��ֵ����r5�������������ʾ���
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

			//��ʾ���Ѽ�¼
		if(xf_zh->level=='S')
		{
			printf("\n++++++++++++++++++++++++++++\n");
			printf("�װ���%s,����%s��%s��%s�չ�����%s��������Ļ�Ա����ΪS,���Բ����ܴ����Żݣ�����Ʒ���ѽ��Ϊ%f��ף���������!\n",xf_zh->Name,r5,r2,r3,x5[xf],jiage);
			printf("++++++++++++++++++++++++++++\n");
			return 0;
		}
		printf("\n++++++++++++++++++++++++++++\n");
		printf("�װ���%s,����%s��%s��%s�չ�����%s����Ļ�Ա����Ϊ%c,���ۺ���Ʒ���Ϊ%f��ף���������!\n",xf_zh->Name,r5,r2,r3,x5[xf],xf_zh->level,jiage);//������ʾ�Ľ���Ǵ��ۺ�Ľ��
		printf("++++++++++++++++++++++++++++\n");
	}

	return 0;
}

int show_balance()//��ʾ�˻����
{
	int bal_id;
	BSTree s_bal;
	float bal_num;
	printf("������Ҫ��ѯ�����˺�!");
	scanf("%d",&bal_id);
	s_bal=SearchBST(q,bal_id);
	if(!s_bal)
	{
		printf("���˻�������!");
		return -1;
	}
	bal_num=s_bal->balance;
	printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("�װ���%s,����˻����Ϊ%f,ף���������!\n",s_bal->Name,bal_num);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	return 0;
}

int show_con_record()//��ʾ���Ѽ�¼
{
	int con_id;
	BSTree s_con;
	p_node_con con;

	printf("������Ҫ��ѯ���Ѽ�¼���˺�!");
	scanf("%d",&con_id);
	s_con=SearchBST(q,con_id);
	if(!s_con)
	{
		printf("���˻�������!");
		return -1;
	}
	con=s_con->first_node_con;
	if(con==NULL)
	{
		printf("�װ���%s,����Ϊֹ�㻹û�����ѹ�ม�\n",s_con->Name);
		return -1;
	}
	printf("=================================\n");
	printf("�װ���%s,������Ѽ�¼Ϊ:\n",s_con->Name);
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

int xiaohu(int xiao_id)//����
{
	BSTree p,p1,plchild,prchild,m=NULL;
	p=q;
	char name[20];

	p1=SearchBST(q,xiao_id);
	if(!p1)
	{
		printf("���˺��û�������!����ʧ��\n");
		return -1;
	}
	if(p1->balance!=0.0)
	{
		printf("�װ���%s,�����Ϊ0�����������!\n",p1->Name);
		return -1;
	}

	while(p)
	{
		if(p->ID==xiao_id)//�ҵ����˻�
			break;
		m=p;//m�Ǹ��˻���˫��
		if(p->ID>xiao_id)
			p=p->lchild;
		else p=p->rchild;
	}
	strcpy(name,p->Name);
	prchild=p;

	if((p->lchild)&&(p->rchild))//��ɾ�˻������Һ��Ӿ���Ϊ��
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
	else if(!p->rchild)//��ɾ�˻�û���Һ��ӵ����
		p=p->lchild;

	else if(!p->lchild)//��ɾ�˻�û�����ӵ����
		p=p->rchild;
	if(!m)//��ɾ�˻�Ϊ�����
		q=p;
	else if(prchild==m->lchild)
		m->lchild=p;
	else
		m->rchild=p;
	delete prchild;
	printf("�˺�%d��%s�û����Ϊ0�������ɹ�!",xiao_id,name);

	return 0;
}
