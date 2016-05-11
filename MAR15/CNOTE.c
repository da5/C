#include<stdio.h>

#define MAX_N 100000
int main(){
	int t, x, y, k, n, i;
	int p, c, flag;
//	int *pages, *cost;
//	
//	pages = (int*)malloc(sizeof(int)*MAX_N);
//	cost  = (int*)malloc(sizeof(int)*MAX_N);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x, &y, &k, &n);
		flag = 0;
		for(i = 0; i<n; i++){
			scanf("%d%d", &p, &c);
			if(flag == 0){
				if(x <= (y+p) && c <= k){
					flag = 1;
				}	
			}
		}
		if(flag == 1){
			printf("LuckyChef\n");
		}else{
			printf("UnluckyChef\n");
		}
	}
	return 0;
}