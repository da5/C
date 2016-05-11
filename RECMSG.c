#include<stdio.h>

int main()
{
	int t, k, i;
	char str[1000];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s",str);
		for(i=0,k=0;str[i]!='\0';i++)
			k += str[i]-'a'+1; 
		printf("%d\n",k);
	}
	return 0;
}

