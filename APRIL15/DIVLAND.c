#include<stdio.h>
#include<stdlib.h>

void quick_sort(unsigned long int *cost,unsigned long int *node,unsigned long int low,unsigned long int high)
{
	unsigned long int pivot,j,temp,i;
	if(low<high)
	{
		pivot = low;
		i = low;
		j = high;

		while(i<j)
		{
			while((cost[i]<=cost[pivot])&&(i<high))
			{
				i++;
			}

			while(cost[j]>cost[pivot]&&j>low)
			{
				j--;
			}

			if(i<j)
			{ 
				temp=cost[i];
				cost[i]=cost[j];
				cost[j]=temp;
				temp=node[i];
				node[i]=node[j];
				node[j]=temp;
			}
		}

		temp=cost[pivot];
		cost[pivot]=cost[j];
		cost[j]=temp;
		temp=node[pivot];
		node[pivot]=node[j];
		node[j]=temp;
		quick_sort(cost, node, low,j-1);
		quick_sort(cost, node, j+1,high);
	}
}

void bubble_sort(unsigned long int *cost,unsigned long int *node,unsigned long int low,unsigned long int high){
	unsigned long int j,temp,i;
	int flag;
	for(i=low+1;i<high-1;i++){
		flag = 0;
		for(j=low;i<high-i-1;i++){
			if(cost[j]<cost[j+1]){
				temp=cost[j];
				cost[j]=cost[j+1];
				cost[j+1]=temp;
				temp=node[j];
				node[j]=node[j+1];
				node[j+1]=temp;
				flag = 1; 
			}
		}
		if(flag==0)
			break;
	}
}

int main()
{
	unsigned long int *cost, *node, n, m, i, j, x, y, c;
	node = (unsigned long int*)malloc(sizeof(unsigned long int)*1000000);
	cost = (unsigned long int*)malloc(sizeof(unsigned long int)*1000000);
	scanf("%lu%lu", &n,&m);
	for(i=0;i<n;i++){
		node[i] = i;
		cost[i] = 0;
	}
	for(i=0;i<m;i++){
		scanf("%lu%lu%lu", &x,&y,&c);
		cost[x] += c;
		cost[y] += c;
	}
	for(i=0;i<n;i++){
		printf("(%lu,%lu) ", node[i], cost[i]);
	}
	printf("\n");
	
//	quick_sort(cost, node, 0, n-1);
	bubble_sort(cost, node, 0, n);
	
	for(i=0;i<n;i++){
		printf("(%lu,%lu) ", node[i], cost[i]);
	}
	printf("\n");
	
	
	for(i = 0;i< n/2; i++)
		printf("%lu ",node[i]);
	printf("\n");

	return 0;
}
