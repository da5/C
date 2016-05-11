#include<stdio.h>

int main(){

	int n1,n2,k1,k2,r;
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	r = (n1%(k1+1))^(n2%(k2+1));
	if(r%2==0)
		printf("Second");
	else
		printf("First");
	return 0;
}