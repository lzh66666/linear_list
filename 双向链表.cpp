#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef float ElemType;
typedef int Status;

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e);
Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e);
DuLinkList GetElem_DuL(DuLinkList L,int i); 
void CreateList_DuL(DuLinkList &L,int n);
void Printlist_DuL(DuLinkList L);

int main(int argc, char** argv) {
	DuLinkList La;
	int n,i;
	ElemType e;
	printf("请输入双向链表的个数:\n");
	scanf("%d",&n) ;
	printf("请输入双向链表的数据:\n");
	CreateList_DuL(La,n);
	Printlist_DuL(La);
	printf("请输入想插入双向链表的位置和元素:\n");
	scanf("%d%f",&i,&e);
	ListInsert_DuL(La,i,e);
	Printlist_DuL(La);
	printf("请输入你想删除的位置:\n");
	scanf("%d",&i);
	ListDelete_Dul(La,i,e);
	Printlist_DuL(La);
	printf("删除的元素是%f\n",e);
	return 0;
}

void CreateList_DuL(DuLinkList &L,int n)
{
	int i;
	DuLinkList p,q;
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->next=NULL; 
	q=L;
    for(i=1;i<n+1;i++)
	{
		p=(DuLinkList)malloc(sizeof(DuLNode));
		scanf("%f",&p->data);
	    q->next=p;
		p->prior=q;
		q=p;
	}
	//q->next=NULL;
	
}

void Printlist_DuL(DuLinkList L)
{
	DuLinkList p;
	p=L->next;
	printf("HEAD->");
	while(p!=NULL)
	{
		printf("%4.2f->",p->data);
		p=p->next;
	}
	printf("END\n");
}

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e)
{
	DuLinkList p,s;
	p=GetElem_DuL(L,i);
	if(p==NULL)
		return ERROR;
	s=(DuLinkList)malloc(sizeof(DuLNode));
	if(s==NULL)
		exit(OVERFLOW);
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}

Status ListDelete_Dul(DuLinkList &L,int i,ElemType &e)
{
	DuLinkList p;
	p=GetElem_DuL(L,i);
	if(p==NULL)
		return ERROR;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return OK;
}

DuLinkList GetElem_DuL(DuLinkList L,int i)
{
	DuLinkList p;
	int j=0;
	p=L->next;
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	if(!p || j>i-1)
	return ERROR;
	return p;
}
