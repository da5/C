#include<stdio.h>

int main()
{
	int t, n, i, max_sum, min_sum, x, contributors;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0,max_sum = 0, min_sum = 0, contributors = 0; i<n; i++)
		{
			scanf("%d",&x);
			if(x>0)
			{
				max_sum += x;
				min_sum += x-1;	
				contributors++;
			}
			
		}
		if(max_sum<100 || min_sum>100)
			printf("NO\n");
		else if(min_sum==100 && max_sum>100)
			printf("NO\n");
		else if(max_sum == 100)
			printf("YES\n");
		else
		{
			if(max_sum - min_sum > contributors)
				printf("NO\n");
			else
				printf("YES\n");
		}
			
	}
	return 0;
}

