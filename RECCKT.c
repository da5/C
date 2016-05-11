#include<stdio.h>

int main()
{
	int t, n , i, j;
	long int arr[1000], max;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&arr[i]);
		max = arr[1]-arr[0];
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(max < arr[j]-arr[i])
					max = arr[j]-arr[i];
		printf("%ld\n", max);
		
	}
	return 0;
}

