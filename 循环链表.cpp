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

LinkList CreateList_L(LinkList &L,int n);//创建链表 
void Printlist_L(LinkList L);//输出链表 
void Lunion(LinkList &La,LinkList &Lb);

int main(int argc, char** argv) {
	LinkList La,Lb,p,q;
	int n;
	printf("请输入循环a链表的长度:\n");
	scanf("%d",&n); 
	printf("请输入链表a的数据:\n"); 
	p=CreateList_L(La,n);
	Printlist_L(La);
	printf("请输入循环b链表的长度:\n");
	scanf("%d",&n);
	printf("请输入链表b的数据:\n");
	q=CreateList_L(Lb,n);
	Printlist_L(Lb);
	Lunion(p,q);
	printf("循环链表合并后:\n");
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
