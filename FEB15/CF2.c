#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int j,n,*arr;
	unsigned long int  x, i, max=0;
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*1000000000);
//	for(i=0;i<1000000000;i++){
//		arr[i] = 0;
//	}
	memset(arr,0,sizeof(*arr)*1000000000);
	for(i=0;i<n;i++){
		scanf("%lu",&x);
		if(x>max)
			max = x;
		arr[x]++;
	}
	for(i=0;i<n-1;i++){
		scanf("%lu",&x);
//		arr[x]--;
	}
	for(i=0;i<n-2;i++){
		scanf("%lu",&x);
		arr[x]--;
	}
	for(i=0;i<=max;i++){
		if(arr[i]>0){
			for(j=0;j<arr[i];j++){
				printf("%lu\n",i);
			}
		}
	}
	return 0;
}
