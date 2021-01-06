#include<stdio.h>
#include<malloc.h>
typedef int ElementType; // ElementType 可定义为任意类型
typedef struct LNode *List;
struct LNode{
	ElementType Data;   //数据域 
	List Next;   // 下一个链表的地址 
}; 
List L;

List MakeEmpty();
int Length(List L);
List FindKth(int K,List L);
List Find(ElementType X,List L);
List Insert(ElementType X,int i,List L);
List Delete(int i,List L);
void Print(List L); 

List MakeEmpty(){
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}

int Length(List L){
	List p = L;
	int len=0;
	while(p){
		p = p->Next;
		len++;
	}
	return len;
} 

List FindKth(int K,List L){
	List p = L;
	int i = 1;
	while(p && i<K){
		p = p->Next;
		i++;
	}
	if(i == K){
		return p;
	}else{
		return NULL;
	}
}

List Find(ElementType X,List L){
	List p = L;
	while(p && p->Data!=X){
		p = p->Next; 
	}
	if(p->Data == X){
		return p;
	}else{
		return NULL;
	}
}

List Insert(ElementType X,int i,List L){
	List p,s;
	if(i==1){
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;
	}
	p = FindKth(i-1,L);
	if(!p){
		printf("error");
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return L;
	}
}

List Delete(int i,List L){
	List p,s;
	if(i==1){
		s=L;
		if(L){
			L = L->Next;
		}else{
			return NULL;
		}
		free(s);
		return L;
	}
	p = FindKth(i-1,L);
	if(!p || !(p->Next)){
		printf("error");
	}else{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return L;
	}
}

void Print(List L){
	List t;
	int flag = 1;
	printf("当前链表为：");
	for(t = L;t;t= t->Next){
		printf("%d ",t->Data);
		flag = 0;
	}
	if(flag){
		printf("NULL");
	}
	printf("\n");
}

int main(){
	L = MakeEmpty();
	Print(L);
	L = Insert(11,1,L);
	L = Insert(25,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
	Print(L);
}
