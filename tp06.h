#ifndef TP06

#define TP06


struct DynamicArray{

   int *arr;
   int len;
   int size;   

};



struct DynamicArray* createArray(int n);

void append(struct DynamicArray* p,int elm);

void delete(struct DynamicArray *p,int index);

void search(struct DynamicArray *p,int elm);

void grow(struct DynamicArray *p);

void shrink(struct DynamicArray *p);

int isArrayFull(struct DynamicArray *p);

int isArrayTooEmpty(struct DynamicArray *p);// if size is less then length/2
int isArrayEmpty(struct DynamicArray *p); // if length == 0 full empty


void shuffleArray(int arr[],int n);

void searchArray(int arr[],int elm,int n);

void swap(int *x,int *y);

int findParent(int arr[],int i);

void merge(int arr[],int m,int n);

int isRepresentative(int arr[],int n);



#endif

