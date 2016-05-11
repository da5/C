#include<stdio.h>

void quick_sort(unsigned long int *arr,unsigned long int low,unsigned long int high)
{
	int pivot,j,temp,i;
	if(low<high)
	{
		pivot = low;
		i = low;
		j = high;

		while(i<j)
		{
			while((arr[i]<=arr[pivot])&&(i<high))
			{
				i++;
			}

			while(arr[j]>arr[pivot])
			{
				j--;
			}

			if(i<j)
			{ 
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}

		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		quick_sort(arr,low,j-1);
		quick_sort(arr,j+1,high);
	}
}

int main()
{
	int t,i,n; 
	unsigned long int s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%lu",&n,&s);
		for(i=n;i>=1;i--){
			if(s<i){
				break;
			}
			s -= i;
		}
		printf("%d\n",i);
	}
	return 0;
}
