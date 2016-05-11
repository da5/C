#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int n,m,k,i,x,j,l,r,max;
	int **left, **right, **cache, *arr;
	
	scanf("%d%d%d",&n,&m,&k);
	arr = (int*)malloc((n+1)*sizeof(int));
	left = (int**)malloc((m+1)*sizeof(int*));
	right = (int**)malloc((m+1)*sizeof(int*));
	cache = (int**)malloc((n+1)*sizeof(int*));
	
	for(i=0;i<=m;i++){
		left[i] = (int*)malloc((n+1)*sizeof(int));
		right[i] = (int*)malloc((n+1)*sizeof(int));
	}
	
	for(i=0;i<=n;i++){
		cache[i] = (int*)malloc((n+1)*sizeof(int));
	}
	
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			left[i][j] = m+1;
			right[i][j] = 0;
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			cache[i][j] = -1;
		}
	}
	
	for(i=1;i<=n;i++){
		scanf("%d",&x);
//		printf("%d\n",x);
		arr[i] = x;
		left[x][i] = i;
		right[x][i] = i;
	}
	
	for(i=1;i<=m;i++){
		x = right[i][1];
		for(j=2;j<=n;j++){
			if(x<right[i][j]){
				x=right[i][j];
			}
			right[i][j] = x;
		}
		x = left[i][n];
		for(j=n-1;j>=1;j--){
			if(x>left[i][j]){
				x=left[i][j];
			}
			left[i][j] = x;
		}
	}
	
//	for(i=1;i<=n;i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	
//	for(i=1;i<=m;i++){
//		printf("m=%d\n",i);
//		for(j=1;j<=n;j++){
//			printf("%d ", right[i][j]);
//		}
//		printf("\n");
//		for(j=1;j<=n;j++){
//			printf("%d ", left[i][j]);
//		}
//		printf("\n");
//	}

	while(k--){
		scanf("%d%d",&l,&r);
		
		if(cache[l][r]!=-1){
			max = cache[l][r];
		}else{
			if(l==r){
				max = 0;
			}else if(l+1==r && arr[l]==arr[r]){
				max = 1;
			}
			else{
				max = 0;
				for(i=1;i<=m;i++){
					if(left[i][l]<m+1 && right[i][r]>0 && right[i][r]>=left[i][l] && left[i][l]<=r && right[i][r]>=l){
						x =  right[i][r] - left[i][l];
						if(x>max){
							max = x;
						}
					}
				}	
			}	
			cache[l][r] = max;
		}

		
		
		
		printf("%d\n", max);
	}
	
	return 0;
}