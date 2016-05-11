#include<stdio.h>
#include<stdlib.h>


int main()
{
	int t;
	unsigned long int i, n, k, total_profit, max_profit, current, ct;
	unsigned long int *time = (unsigned long int*)malloc(sizeof(unsigned long int)*100000);
	unsigned long int *profit = (unsigned long int*)malloc(sizeof(unsigned long int)*100000);
	scanf("%d", &t);
	while(t--)
	{
		total_profit = 0; 
		scanf("%lu%lu",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lu", &time[i]);
		for(i=0;i<n;i++)
			scanf("%lu", &profit[i]);
		
		while(k > 0)
		{
			max_profit = (k/time[0])*profit[0];
			ct = time[0];
			for(i=1;i<n;i++)
			{
				current = (k/time[i])*profit[i];
				if(current > max_profit)
				{
					max_profit = current;
					ct = time[i];
				}
					
			}
			total_profit += max_profit;
			k = k%ct;
			// printf("%lu\n", total_profit);	
			if(max_profit == 0)
				break;		
		}

		
		printf("%lu\n", total_profit);
	}
	return 0;
}
