#include<stdio.h>
#include<stdlib.h>


int main()
{
	int t, flag;
	unsigned long int n ,k, x, ksum;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%lu%lu", &n, &k);
		ksum = 0;
		flag = 0;
		while(k--)
		{
			scanf("%lu", &x);
			ksum += x;
			if(x==1)
				flag = 1;
		}	
		if(flag==1)
			printf("Chef\n");
		else
		{
			if( ( (n*(n+1)/2) - ksum )%2 == 1 )
				printf("Mom\n");
			else
				printf("Chef\n");	
		}
	}
	
		
	
	return 0;
}
