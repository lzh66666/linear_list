#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef float ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList; 

Status InitList(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

Status ListInsert(SqList &L,int i,ElemType e){
	ElemType *newbase,*q,*p;
	if(i<i || i>L.length)
		return ERROR;
	if(L.length>=L.listsize){
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(newbase == NULL){
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i-1]);
	for(p = &(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
}

int LocateElem(SqList L,ElemType e){
	int i=1;
	ElemType *p;
	p = L.elem;
	while(i<=L.length && *p++!=e)
		i++;
	if(i<=L.length)
		return i;
	else
		return 0;
}

void MergetList(SqList La,SqList Lb,SqList &Lc){
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa=La.elem;
	pb=Lb.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	pc=Lc.elem=(ElemType *)malloc(Lc.listsize *sizeof(ElemType));
	if(!Lc.elem)
		exit(OVERFLOW);
    pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last && pb<=pb_last){
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
	while(pa<=pa_last)
		*pc++=*pa++;
	while(pb<=pb_last)
		*pc++=*pb++;
}

Status ListDelet(SqList &L,int i,ElemType &e){
	ElemType *p,*q;
	if(i<1 || i>L.length)
		return ERROR;
	p=&(L.elem[i-1]);
	e=*q;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
		*(p-1) = *p;
	--L.length;
	return OK;
	
}

int ListLength(SqList L){
	int i=0;
	while(L.elem[i])
		i++;
	return i;
	
}

Status GetElem(SqList &L,int i,ElemType &e){
	
	e=L.elem[i-1];
	return OK;
	
}


void Lunion(SqList &La,SqList Lb){
	int i;
	ElemType e;
	int La_len,Lb_len;
	La_len=ListLength(La);
	Lb_len=ListLength(Lb);
	
	for(i=1;i<=Lb_len;i++){
		GetElem(Lb,i,e);
		if(!LocateElem(La,e))
			ListInsert(La,++La_len,e);
	}
}

int main(int argc, char** argv) {
	
 SqList La,Lb,Lc;//定义3个表
	ElemType e;
	Status i=0,n,m,flag; 
	InitList(La); 
	InitList(Lb);
	InitList(Lc);
	
	//给ab表赋值 
	printf("请输入您想要在a中输入的元素个数:\n"); 
	scanf("%d",&n);
	La.length=n;
	for(i=0;i<n;i++)
	{
		scanf("%f",&La.elem[i]);
	}
	printf("请输入您想要在b中输入的元素个数:\n"); 
	scanf("%d",&m);
	Lb.length=m;
	for(i=0;i<m;i++)
	{
		scanf("%f",&Lb.elem[i]);
	}
	
	//插入一个值
	printf("请输入你想在a表插入的元素位置和元素:\n");
	
	scanf("%d%f",&i,&e); 
	ListInsert(La,i,e);
	for(i=0;i<n+1;i++)
	{
		printf("%4.2f ",La.elem[i]);
	}
	printf("\n");
	printf("插入的元素为%4.2f\n",e);
	
	//删除一个值
	printf("请输入在a表中删除的元素位置:\n");
	scanf("%d",&i); 
	ListDelet(La,i,e);
	for(i=0;i<n;i++)
	{
		printf("%4.2f ",La.elem[i]);
	}
	printf("\n");
	printf("删除的元素为%f:\n",e);
	
	//对线性表进行查找
	printf("请输入你想在a表中想找到的元素:\n");
	scanf("%f",&e); 
	i=LocateElem(La,e);
	printf("元素的位置为%d\n",i);
	printf("\n");
		
	La.length=n;
	//对a,b俩表进行有序合并C	
	MergetList(La,Lb,Lc);

	printf("合成c表为:\n");
	for(i=0;i<n+m;i++)
	{	
		printf("%4.2f ",Lc.elem[i]);	
	}
//	对la和lb进行合并
    printf("\n");
    printf("aUb的结果：\n");
    Lunion(La,Lb);
	for(i=0;i<La.length;i++)
	{
		printf("%4.2f ",La.elem[i]);
	} 
	
	return 0;
}
