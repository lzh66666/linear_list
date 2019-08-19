#include <iostream>
#include <stdlib.h>


#define  ElemType float
#define  Status  int 
#define OK 1
#define ERROR 0
#define OVERFLOW 0
 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList; 

void CreateList_L(LinkList &L,int n,int j);//�������� 
void Printlist_L(LinkList L);//������� 
Status GetElem_L(LinkList L,int i,ElemType &e);//�������ĵ�i��Ԫ��
Status ListInert_L(LinkList &L,int i,ElemType e);//�������в���ĳ��ֵ
Status ListDelete_L(LinkList &L,int i,ElemType &e);//��������ɾ��ĳ��ֵ 
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc);//��������������ϲ�Ϊһ���������� 

int main(int argc, char** argv) {
	int n,i,j=1,flag=0; 
	ElemType e;
	LinkList La,Lb,Lc;
	char m;
	
	printf("------------------------------------------\n");//��ʼ������
	printf("����밴ͷ�巨��������������1\n����밴β�巨��������������2\n");
	scanf("%d",&i);
	
	printf("�������������La������������a,�������������Lb������������b,������˳�������s\n");
	
	while(1)
	{
	    m=getchar();
		if(m=='a')
		{
			flag++;
			printf("����������a�ĳ��ȣ�\n"); 
			scanf("%d",&n);
			printf("����������a��ֵ:\n");
			CreateList_L(La,n,i);
			Printlist_L(La);
			printf("\n");
			printf("�����������a��ĳ��ֵ������1\n��������ĳ��ֵ������2\n�����ɾ��ĳ��ֵ������3\n");
			scanf("%d",&j);
			switch(j)
			{
				
			    case 1:
				printf("\n------------------------------------------\n");//�������ĵ�i��Ԫ��
				printf("�����������ȡa����ĵڼ���ֵ:\n");
				scanf("%d",&i);
				GetElem_L(La,i,e);
				printf("��%d��ֵ��%4.2f\n",i,e);
				break;
				
			    case 2:
				printf("\n------------------------------------------\n");//�������в���ĳ��ֵ
				printf("�����������������a��λ�ú���ֵ:\n");
				scanf("%d%f",&i,&e);
				ListInert_L(La,i,e);
				Printlist_L(La);
				break;
					
				case 3:
				printf("\n------------------------------------------\n");//��������ɾ��ĳ��ֵ
				printf("����������ɾ������a��λ��:\n");
				scanf("%d",&i);
				ListDelete_L(La,i,e);
				Printlist_L(La);
				printf("\nɾ����Ԫ����%4.2f\n",e);
				break;	
			}
		} 
		
		else if(m=='b')
		{
			flag++;
			printf("����������b�ĳ��ȣ�\n"); 
			scanf("%d",&n);
			printf("����������b��ֵ:\n"); 
			CreateList_L(Lb,n,i);
			Printlist_L(Lb);
			printf("\n");
			printf("�����������b��ĳ��ֵ������1\n��������ĳ��ֵ������2\n�����ɾ��ĳ��ֵ������3\n");
			
			scanf("%d",&j);
			switch(j)
			{	
			    case 1:
				printf("\n------------------------------------------\n");//�������ĵ�i��Ԫ��
				printf("�����������ȡb����ĵڼ���ֵ:\n");
				scanf("%d",&i);
				GetElem_L(Lb,i,e);
				printf("��%d��ֵ��%4.2f\n",i,e);
				break;
				
			    case 2:
				printf("\n------------------------------------------\n");//�������в���ĳ��ֵ
				printf("�����������������b��λ�ú���ֵ:\n");
				scanf("%d%f",&i,&e);
				ListInert_L(Lb,i,e);
				Printlist_L(Lb);
				break;
					
				case 3:
				printf("\n------------------------------------------\n");//��������ɾ��ĳ��ֵ
				printf("����������ɾ������b��λ��:\n");
				scanf("%d",&i);
				ListDelete_L(Lb,i,e);
				Printlist_L(Lb);
				printf("\nɾ����Ԫ����%4.2f\n",e);	
			    break;
			}	    
		}
		else if(m=='s')
		break;	
	}
	
	if(flag==2)
    {
    	printf("���Ҫ�ϲ�����a��b��������1����������0\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("\n------------------------------------------\n");//��������������ϲ�Ϊһ����������
			MergeList_L(La,Lb,Lc);
			printf("�ϲ����������Ϊ:\n");
			Printlist_L(Lc);
			printf("\n------------------------------------------\n");		
		} 
	    
	}
	
	return 0;
}

void CreateList_L(LinkList &L,int n,int j)
{
	int i;
	LinkList p,q;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;	//�Ƚ���һ����ͷ���ĵ����� 
	//ͷ�巨 
	if(j==1)
	{
		for(i=n;i>0;i--)
		{
			p=(LinkList)malloc(sizeof(LNode));
			scanf("%f",&p->data);
			p->next=L->next;
			L->next=p;
		}	
	}
	
	//β�巨 
	else if(j==2)
	{
		q=L;
		for(i=1;i<n+1;i++)
		{
			p=(LinkList)malloc(sizeof(LNode));
			scanf("%f",&p->data);
			p->next=NULL;
			q->next=p;
			q=p;	
		}	
	}
	
}

void Printlist_L(LinkList L)
{
	L=L->next;
	printf("HEAD->");
	while(L!=NULL)
	{
		printf("%4.2f->",L->data);
		L=L->next;
	}
	printf("END");
}

Status GetElem_L(LinkList L,int i,ElemType &e)
{
	LinkList p;
	p=L->next;
	int j=1;
	while(p && j<i){
		p=p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	e=p->data;
	return OK;
}

Status ListInert_L(LinkList &L,int i,ElemType e)
{
	LinkList p=L,q;
	int j=0;
	while(p && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1)
		return ERROR;
	q=(LinkList)malloc(sizeof(LNode));
	q->data=e; 
	q->next=p->next;
	p->next=q;
	return OK;
}

Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LinkList p=L,q;
	int j=0;
	while(p->next && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1)
		return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
} 
 void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LinkList pa,pb,pc;
    pa=La->next;
    pb=Lb->next;
    Lc=pc=La;
    while(pa && pb)
    {
    	if(pa->data<=pb->data)
    	{
    		pc->next=pa;
    		pc=pa;
    		pa=pa->next;
		}
		else
		{
    		pc->next=pb;
    		pc=pb;
    		pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(Lb); 			//�ͷ�Lb��ͷ��� 
} 
 
 
