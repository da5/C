#include<stdio.h>

int main()
{
	int t,i,n,x,maxn;
	int freq[100001], max; 
	scanf("%d", &t);
	while(t--)
	{
		for(i=1;i<=100000;i++)
			freq[i] = 0;
		scanf("%d", &n);
		for(maxn=-1,i=0;i<n;i++){
			scanf("%d", &x);
			freq[x]++;
			if(maxn<x)
				maxn=x;

		}


		for(max = freq[1],i=2;i<=maxn;i++){
			// printf(">>>>> %d\n",freq[i]);
			if(max<freq[i])
				max = freq[i];
		}
		printf("%d\n", n-max);
	}
	return 0;
}
