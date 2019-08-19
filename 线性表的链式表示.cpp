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

void CreateList_L(LinkList &L,int n,int j);//创建链表 
void Printlist_L(LinkList L);//输出链表 
Status GetElem_L(LinkList L,int i,ElemType &e);//获得链表的第i个元素
Status ListInert_L(LinkList &L,int i,ElemType e);//在链表中插入某个值
Status ListDelete_L(LinkList &L,int i,ElemType &e);//在链表中删除某个值 
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc);//将两个有序链表合并为一个有序链表 

int main(int argc, char** argv) {
	int n,i,j=1,flag=0; 
	ElemType e;
	LinkList La,Lb,Lc;
	char m;
	
	printf("------------------------------------------\n");//初始化链表
	printf("如果想按头插法输入链表请输入1\n如果想按尾插法输入链表请输入2\n");
	scanf("%d",&i);
	
	printf("如果想输入链表La的数据请输入a,如果想输入链表Lb的数据请输入b,如果想退出请输入s\n");
	
	while(1)
	{
	    m=getchar();
		if(m=='a')
		{
			flag++;
			printf("请输入链表a的长度：\n"); 
			scanf("%d",&n);
			printf("请输入链表a的值:\n");
			CreateList_L(La,n,i);
			Printlist_L(La);
			printf("\n");
			printf("如果想获得链表a的某个值请输入1\n如果想插入某个值请输入2\n如果想删除某个值请输入3\n");
			scanf("%d",&j);
			switch(j)
			{
				
			    case 1:
				printf("\n------------------------------------------\n");//获得链表的第i个元素
				printf("请输入你想获取a链表的第几个值:\n");
				scanf("%d",&i);
				GetElem_L(La,i,e);
				printf("第%d个值是%4.2f\n",i,e);
				break;
				
			    case 2:
				printf("\n------------------------------------------\n");//在链表中插入某个值
				printf("请输入你想插入链表a的位置和数值:\n");
				scanf("%d%f",&i,&e);
				ListInert_L(La,i,e);
				Printlist_L(La);
				break;
					
				case 3:
				printf("\n------------------------------------------\n");//在链表中删除某个值
				printf("请输入你想删除链表a的位置:\n");
				scanf("%d",&i);
				ListDelete_L(La,i,e);
				Printlist_L(La);
				printf("\n删除的元素是%4.2f\n",e);
				break;	
			}
		} 
		
		else if(m=='b')
		{
			flag++;
			printf("请输入链表b的长度：\n"); 
			scanf("%d",&n);
			printf("请输入链表b的值:\n"); 
			CreateList_L(Lb,n,i);
			Printlist_L(Lb);
			printf("\n");
			printf("如果想获得链表b的某个值请输入1\n如果想插入某个值请输入2\n如果想删除某个值请输入3\n");
			
			scanf("%d",&j);
			switch(j)
			{	
			    case 1:
				printf("\n------------------------------------------\n");//获得链表的第i个元素
				printf("请输入你想获取b链表的第几个值:\n");
				scanf("%d",&i);
				GetElem_L(Lb,i,e);
				printf("第%d个值是%4.2f\n",i,e);
				break;
				
			    case 2:
				printf("\n------------------------------------------\n");//在链表中插入某个值
				printf("请输入你想插入链表b的位置和数值:\n");
				scanf("%d%f",&i,&e);
				ListInert_L(Lb,i,e);
				Printlist_L(Lb);
				break;
					
				case 3:
				printf("\n------------------------------------------\n");//在链表中删除某个值
				printf("请输入你想删除链表b的位置:\n");
				scanf("%d",&i);
				ListDelete_L(Lb,i,e);
				Printlist_L(Lb);
				printf("\n删除的元素是%4.2f\n",e);	
			    break;
			}	    
		}
		else if(m=='s')
		break;	
	}
	
	if(flag==2)
    {
    	printf("如果要合并链表a和b，请输入1，否则输入0\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("\n------------------------------------------\n");//将两个有序链表合并为一个有序链表
			MergeList_L(La,Lb,Lc);
			printf("合并后的新链表为:\n");
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
	L->next=NULL;	//先建立一个带头结点的单链表 
	//头插法 
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
	
	//尾插法 
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
	free(Lb); 			//释放Lb的头结点 
} 
 
 
