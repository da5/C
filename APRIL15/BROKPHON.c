#include<stdio.h>
#define N 1000000000

int main()
{
	int t,i,n, prev_flag;
	unsigned long int prev, curr, result;
//	int *arr;
//	arr = (int*)malloc(sizeof(int)*N);
	scanf("%d", &t);
	while(t--)
	{
		result = 0;
		prev_flag = 0;
		scanf("%d", &n);
		scanf("%lu",&prev);
		for(i=1;i<n;i++){
			scanf("%lu",&curr);
			if(prev!=curr){
				if(prev_flag==0){
					result += 2;
				}else{
					result += 1;
				}
				prev_flag=1;
			}
			else{
				prev_flag=0;
			}
			prev = curr;
		}
		printf("%lu\n",result);
	}
	return 0;
}
