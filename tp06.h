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

int isArrayTooEmpty(struct DynamicArray *p);



void shuffleArray(int arr[],int n);

void searchArray(int arr[],int elm,int n);


int findParent(int arr[],int i);

void merge(int arr[],int m,int n);





#endif

