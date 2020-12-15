#include <stdio.h>
#include <time.h>
#include "tp06.h"
#include <stdlib.h>

void shuffleArray(int arr[],int n)
{
	int randInt1;
	int randInt2;

	for(int i=0;i<n;i++)
	{
		randInt1=rand()%100;
		randInt2=rand()%100;
		swap(&arr[randInt1],&arr[randInt2]);
		


	}


}

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void searchArray(int arr[],int elm,int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==elm)
			return;

	}

}







struct DynamicArray *createArray(int n)
{
	struct DynamicArray *p = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));

	p->len=0;
	p->size=n;
	p->arr=(int *)malloc(sizeof(int)*p->size);

	return p;
}

void append(struct DynamicArray* p,int elm)
{
	
	if(isArrayFull(p))
	{
		grow(p);
	}

	p->arr[p->len]=elm;
	p->len++;

}


void delete(struct DynamicArray* p,int index)
{
	
	for(int i=index;i<p->len;i++)
	{
		p->arr[i]=p->arr[i+1];

	}


	p->len=p->len-1;

	if(isArrayTooEmpty(p))
	{
		shrink(p);
	}


}

void search(struct DynamicArray *p,int elm)
{
	if(isArrayEmpty(p))
		return;
	
	for(int i=0;i<p->len;i++)
	{
		if(p->arr[i]==elm)
		{
			delete(p,i);
			return;
		}


	}

}



void shrink(struct DynamicArray *p)
{

	p->arr = realloc(p->arr,sizeof(int)*(p->size/2));
	p->size=p->size/2;

}

void grow(struct DynamicArray *p)
{
	p->arr = realloc(p->arr,sizeof(int)*(p->size*2));
	p->size=p->size*2;
}

int isArrayFull(struct DynamicArray *p)
{
	if(p->len==p->size)
	
		return 1;
	return 0;

}

int isArrayTooEmpty(struct DynamicArray *p)
{
	if(p->len<(p->size/2))
		return 1;
	return 0;
}

int isArrayEmpty(struct DynamicArray *p)
{
	if(p->len==0)
	{
		return 1;
	}
	return 0;

}





int findParent(int arr[],int n)
{
	if(arr[n]<0)
	{
		return n;
	}
	
	return findParent(arr,arr[n]);

}

void merge(int arr[],int m,int n)
{
	if(findParent(arr,m)==findParent(arr,n))
			return;
	arr[findParent(arr,m)]=findParent(arr,n);
}

int isRepresentative(int arr[],int n)
{
	if(arr[n]<0)
		return 1;
	else 
		return 0;
}










 
