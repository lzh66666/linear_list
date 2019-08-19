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

LinkList CreateList_L(LinkList &L,int n);//�������� 
void Printlist_L(LinkList L);//������� 
void Lunion(LinkList &La,LinkList &Lb);

int main(int argc, char** argv) {
	LinkList La,Lb,p,q;
	int n;
	printf("������ѭ��a����ĳ���:\n");
	scanf("%d",&n); 
	printf("����������a������:\n"); 
	p=CreateList_L(La,n);
	Printlist_L(La);
	printf("������ѭ��b����ĳ���:\n");
	scanf("%d",&n);
	printf("����������b������:\n");
	q=CreateList_L(Lb,n);
	Printlist_L(Lb);
	Lunion(p,q);
	printf("ѭ������ϲ���:\n");
	Printlist_L(p);
	return 0;
}
LinkList CreateList_L(LinkList &L,int n)
{
	int i;
	LinkList p,q;
	q=L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=1;i<n+1;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%f",&p->data);
		p->next=NULL;
		q->next=p;
		q=p;	
	}
	p->next=L;	
	return p;
}

void Printlist_L(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%4.2f ",p->data);
		p=p->next;
		if(p==L)
			break;
	}
	printf("\n");
}

void Lunion(LinkList &La,LinkList &Lb)
{
	LinkList p;
	p=La->next;
	La->next=Lb->next->next;
	free(Lb->next);
	Lb->next=p;
	La=p;
}
