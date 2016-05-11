#include<stdio.h>
#include<stdlib.h>


int main()
{
	int t,i,n,k, a,b;
	unsigned long int result;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n,&k);
		result = 1;
		if(n-k>k){
			a = n-k;
			b = k;
		}else{
			b = n-k;
			a = k;
		}
		for(i=a+1;i<=n;i++)
			result *= i;
		for(i=b;i>1;i--)
			result /= i;
		for(i=k;i>1;i--){
			result = (result*i)%1000000007;
			printf("--->  %lu\n", result);	
		}
			
		printf("%lu\n", result);		
	}
	return 0;
}
