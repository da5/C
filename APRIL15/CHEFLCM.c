#include<stdio.h>
int main()
{
	int t;
	unsigned long int n, i, result;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lu", &n);
		result = n;
		if(n>1)
			result += 1;
		for(i=n/2;i>=2;i--){
			if(n%i==0)
				result += i;
		}
		printf("%lu\n",result);
	}
	return 0;
}
