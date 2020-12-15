#include <stdio.h>
#include <time.h>
#include "tp06.h"
#include "math.h"


int main()
{
	time_t start,end;
	double time_elapsed=0.0;

	int arr[100];
	
	for(int i=0;i<100;i++)
	{
		arr[i]=i+1;

	}

	shuffleArray(arr,100);

	for(int i=0;i<100;i++)
	{
		start=clock();
		searchArray(arr,i+1,100);
		end=clock();

		time_elapsed+=end-start;
	}

	printf("\n Soru 1) Arama icin gecen ortalama süre %f mikro saniye",(time_elapsed*pow(10,6)/CLOCKS_PER_SEC/100));

	///soru2
	

	struct DynamicArray* p = createArray(2);

	for(int i=0;i<100;i++)
	{
		append(p,i+1);
	}

	shuffleArray(p->arr,100);

	time_elapsed=0.0;

	for(int i=0;i<100;i++)
	{
		start=clock();
		search(p,i+1); //search fonksiyonu bulduğu indexi ayrıca delete fonksiyonu çağırarak silmektedir. Eğer dizi için ayrılmış memory dizi eleman sayısının 2 katından büyük ise memory 2ye bölünerek küçülür 
		end=clock();
		
	}
	time_elapsed+=end-start;
	printf("\n Soru 2) Dynamic Array arama icin gecen ortalama süre %f mikro saniye\n",(time_elapsed*pow(10,6)/CLOCKS_PER_SEC/100));




	// 3. soru
	

	int sehirlerParent[82];

	for(int i=0;i<82;i++)
	{
		sehirlerParent[i]=-1;
	}


	merge(sehirlerParent,34,35);
	merge(sehirlerParent,35,9);
	merge(sehirlerParent,9,20);
	merge(sehirlerParent,1,33);
	merge(sehirlerParent,1,27);
	merge(sehirlerParent,27,63);
	merge(sehirlerParent,34,41);
	merge(sehirlerParent,14,6);
	merge(sehirlerParent,41,14);
	merge(sehirlerParent,34,22);
	merge(sehirlerParent,34,41);
	merge(sehirlerParent,41,54);
	merge(sehirlerParent,6,51);
	merge(sehirlerParent,51,1);
	merge(sehirlerParent,16,26);
	

	
	struct DynamicArray **sets=(struct DynamicArray **)malloc(sizeof(struct DynamicArray*)*82);
	
	for(int i=1;i<82;i++)
	{
		if(isRepresentative(sehirlerParent,i))
		{

			sets[i]=createArray(2);
		}
		else
			sets[i]=NULL;
				
			
	}

	for(int i=1;i<82;i++)
	{
		append(sets[findParent(sehirlerParent,i)],i);
	}


	for(int i=1;i<82;i++)
	{
		
		if(sets[i]==NULL)
			continue;

		for(int j=0;j<sets[i]->len;j++)
		{

			printf("%d ",sets[i]->arr[j]);
		}


		printf("\n");
	}

	printf("\n 1. ve 2. sorunun cevabi yukardadir, Dynamic arrayde dinamik olarak arrayi kücülttüğümüz için arama süresi daha kısa sürmektedir");







		


}
