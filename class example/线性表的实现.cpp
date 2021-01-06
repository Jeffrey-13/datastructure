#include<stdio.h>
#define MAXSIZE 100
#include<malloc.h> 
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
}; 
List L;

List MakeEmpty();
int Find(ElementType X,List L);
void Insert(ElementType X,int i,List L);
void Delete(int i,List L);
ElementType FindKth(int k,List L);
int Length(List L);

List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L ->Last = -1;
	return L;
}

int Find(ElementType X,List L){
	int i=0;
	while(i<=L->Last && L->Data[i] != X)
		i++;
	if(L->Last < i)
		return -1;
	else
		return i;
}

void Insert(ElementType X,int i,List L){
	int j;
	if(L->Last == MAXSIZE-1){
		printf("表满");
		return ;
	}
	
	if(i<0 || L->Last+1<i){
		printf("位置不合法");
		return ;
	}
	
	for(j = L->Last;j>=i;j--)
		L->Data[j+1] = L->Data[j];
	L->Data[i]=X;
	L->Last++;
	return;
}

void Delete(int i,List L){
	int j;
	if(i<0|| L->Last<i){
		printf("don't exist");
		return ;
	}
	for(j=i;j<=L->Last;j++)
		L->Data[j-1]  = L->Data[j];
	L->Last--;
	return;
}

// 按序查找
ElementType FindKth(int K,List L){
	if(K < 0 || L->Last < K){  //位置越界
        printf("L->Data[%d]不存在元素",K);
    }
    return L->Data[K];
}
//ElementType FindKth(int K,List L){
//	if(K<0||L->Last < K){
//		printf("dont exist");
//		return ; 
//	}
//	return L->Data[K];
//}

int Length(List L){
	return L ->Last+1;
}

int main(){
	int i = 0;
	L = MakeEmpty();
	Insert(11,0,L);
	Insert(9,0,L);
	Insert(5,0,L);
	Insert(7,0,L);
	Insert(18,0,L);
	for(i=0;i<Length(L);i++)
		printf("%d",L->Data[i]);
}
