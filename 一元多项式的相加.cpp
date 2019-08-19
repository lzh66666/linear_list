#include <iostream>
#include <stdlib.h>

typedef struct Polynode{
	int coef,exp;
	struct Polynode *next;
}Polynode,*Polylist; 

Polylist Polycreate(int n);
void AddPolyn(Polylist pa,Polylist pb,Polylist &pc);
void PrintPolyn(Polylist L,int n);

int main(int argc, char** argv) 
{
	int n,m; 
	Polylist pa,pb,pc;
	printf("请输入pa链表元素的个数:\n");
	scanf("%d",&n);
	printf("请输入pa链表的底数和指数:\n");
	pa=Polycreate(n);
	PrintPolyn(pa,n);
	printf("请输入pb链表元素的个数:\n");
	scanf("%d",&m);
	printf("请输入pb链表的底数和指数:\n");
	pb=Polycreate(m);
	PrintPolyn(pb,m);
	printf("两个多项式相加后的结果为:\n");
	AddPolyn(pa,pb,pc);
	PrintPolyn(pc,n+m); 
	return 0;
}

void PrintPolyn(Polylist L,int n)
{
	Polylist p;
	int i=0;
	p=L->next;
	while(p && i<n)
	{
		i++;
		printf("(%d,%d)  ",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}

Polylist Polycreate(int n)
{
	Polylist head,rear,s;
	int c=1,e,i=1;
	head=(Polylist)malloc(sizeof(Polynode));
	rear=head;
	while(c!=0 && i<=n)
	{
		i++;
		scanf("%d,%d",&c,&e);
		s=(Polylist)malloc(sizeof(Polynode));
		s->coef=c;
		s->exp=e;
		rear->next=s;
		rear=s;
	}
	rear->next=NULL;
	return head;
}

void AddPolyn(Polylist pa,Polylist pb,Polylist &pc)
{
	int sum=0;
	Polylist r,Lc;
	pc=Lc=pa;
	pa=pa->next;
	pb=pb->next;
	
	
	while(pa!=NULL && pb!=NULL)
	{
		if(pa->exp<pb->exp)
		{
			Lc->next=pa;
			Lc=pa;
			pa=pa->next;
		}
		else if(pa->exp==pb->exp)
		{
			sum=pa->coef+pb->coef;
			if(sum!=0)
			{
				pa->coef=sum;
				Lc->next=pa;
				Lc=pa;
				pa=pa->next;
				r=pb;
				pb=pb->next;
				free(r);
			}
			else
			{
				r=pa;
				pa=pa->next;
				free(r);
				r=pb;
				pb=pb->next;
				free(r);
			}
		}
		else
		{
			Lc->next=pb;
			Lc=pb;
			pb=pb->next;
		}
	}
	Lc->next=pa?pa:pb;
	
}
