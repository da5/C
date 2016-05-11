#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_N 100001
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b)) 
//int arr1[6101],arr2[6101],len;
//char str[6101];
// 
//int lcs(int *arr1, int *arr2,  char *str1, char *str2, int len){
//	int flag = 0,i,j;
////	printf("%s %s=",str1, str2); 
////	len = strlen(str);
//	 
//	for(i=0;i<len+1;i++)
//		arr1[i] = arr2[i]= 0;
//	 
//	for(i=1;i<=len;i++){
//		for(j=1;j<=len;j++){
//			if(flag)
//			{
//				if(str1[i-1]==str2[j-1])
//					arr2[j] = arr1[j-1]+1;
//				else
//					arr2[j] = max(arr1[j],arr2[j-1]);
//			}
//			else
//			{
//				if(str1[i-1]==str2[j-1])
//					arr1[j] = arr2[j-1]+1;
//				else
//					arr1[j] = max(arr2[j],arr1[j-1]);
//			}
//		 
//		}
//		flag = 1 - flag;
//	}
//	
//	if(flag){
////		printf("%d\n", arr1[len]);
//		return arr1[len];
//	}else{
////		printf("%d\n", arr2[len]);
//		return arr2[len];
//	}
//		
//}

unsigned long int transform0(char *str1, char *str2, int n, int type){
	int i, j;
	unsigned long int score = 0;
	for(i=0;i<n;i++){
		if(str1[i]!=str2[i])
			score++;
	}
	return (score/2);
}

unsigned long int transform1(char *str1, char *str2, int n, int type,int *arr1,int *arr2){
	int i, j, b, g, diff;
	unsigned long int score = 0;
	for(i=0, b=0,g=0; i<n; i++){
		if(str1[i]!=str2[i]){
			if(str2[i]=='B'){
				arr1[b] = i;
				b++;
			}else{
				arr2[g] = i;
				g++;
			}
				
		}
	}
	while(b>0){
		diff = abs(arr1[b-1]-arr2[g-1]);
		if(type==2){
			score+=diff*diff;
		}else{
			score+=diff;
		}
		
		b--;
		g--;
	}
	return score;
}

unsigned long int transform2_calculator(char *str, int n,int *arr1, int b, int g){
	int i;
	unsigned long int score = 0;
	for(i=0;i<n;i++){
		if(str[i]=='B'){
			arr1[i] = b;
			b = b + 2;
		}else{
			arr1[i] = g;
			g = g + 2;
		}
	}
	for(i=0;i<n;i++){
		score += abs(i-arr1[i]);
//		printf("%d ",arr1[i]);
	}
	return score/2;
}

unsigned long int transform2(char *str, int n,int *arr1, int ctr_g, int ctr_b){
	int i, j, b, g,  flag, temp;
	unsigned long int score,score_;
	if(ctr_g<ctr_b){
		b=0;
		g=1;
		score = transform2_calculator(str, n,arr1, b,  g);
	}else if(ctr_g>ctr_b){
		g=0;
		b=1;
		score = transform2_calculator(str, n,arr1, b,  g);
	}else{
		b=0;
		g=1;
		score = transform2_calculator(str, n,arr1, b,  g);
		g=0;
		b=1;
		score_ = transform2_calculator(str, n,arr1, b,  g);
		if(score_<score)
			score = score_;
	} 
	
		
//	printf("%lu\n", score);	
//	for(i=0,score =0;i<n-1;i++){
//		flag = 0;
//		for(j=0;j<n-i-1;j++){
//			if(arr1[j]>arr1[j+1]){
//				temp = arr1[j];
//				arr1[j] = arr1[j+1];
//				arr1[j+1] = temp;
//				score++;
//				flag = 1;
//			}
//		}
//		if(flag==0)
//			break;
//	}
//	for(i=0;i<n;i++)
//		printf("%d ",arr1[i]);
//	printf("\n");
	return score;
}

unsigned long int transform(char *str1, char *str2, int n, int type,int *arr1,int *arr2){
	unsigned long int score = 0;
	switch(type){
		case 0:
			score = transform0(str1, str2, n, type);
			break;
		case 1:
			score = transform1(str1, str2, n, type, arr1, arr2);
			break;
	}
	return score;
}

void analyze_target(char *str,char *target1,char *target2, int *ctr_g, int *ctr_b, int n){
	int i;
//	printf("%d %d\n",*ctr_b, *ctr_g);
	for(i=0;i<n;i++){
		if(str[i]=='G')
			(*ctr_g)++;
		else
			(*ctr_b)++;
	}
//	printf("%d %d\n",*ctr_b, *ctr_g);
	if(abs((*ctr_g)-(*ctr_b)) <= 1){
		if((*ctr_g)>(*ctr_b)){
			for(i=0;i<n/2;i++){
				target1[i*2] = 'G';
				target1[i*2+1] = 'B';
			}
			target1[n-1] = 'G';
			target1[n]='\0';
		}else if((*ctr_g)<(*ctr_b)){
			for(i=0;i<n/2;i++){
				target1[i*2] = 'B';
				target1[i*2+1] = 'G';
			}
			target1[n-1] = 'B';
			target1[n]='\0';
		}else{
			for(i=0;i<n/2;i++){
				target1[i*2] = 'B';
				target1[i*2+1] = 'G';
				target2[i*2] = 'G';
				target2[i*2+1] = 'B';
			}
			target1[n]='\0';
			target2[n]='\0';
		}
	}else{
		target1[0]='\0';
		target2[0]='\0';
	}
}


int main(){
	int t, type, ctr_g, ctr_b, n;
	unsigned long int score1, score2;
	int *arr1, *arr2;
	char *str, *target1, *target2;
	
	arr1 = (int*)malloc(sizeof(int)*MAX_N);
	arr2 = (int*)malloc(sizeof(int)*MAX_N);
	str = (char*)malloc(sizeof(char)*MAX_N);
	target1 = (char*)malloc(sizeof(char)*MAX_N);
	target2 = (char*)malloc(sizeof(char)*MAX_N);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d", &type);
		scanf("%s", str);
		n = strlen(str);
		ctr_b = ctr_g = 0;
		analyze_target(str, target1, target2, &ctr_g, &ctr_b, n);
		if(type!=2){
//			if(type==1){
//				printf("> %lu\n", transform2(str, n, arr1, ctr_g, ctr_b));
//			}
			if(ctr_b==ctr_g){
				if(strcmp(target1,str)==0 || strcmp(target2,str)==0){
					printf("0\n");	
				}else{
					score1 = transform(target1,str, n, type, arr1, arr2);
					score2 = transform(target2,str, n, type, arr1, arr2);
					printf("%lu\n", min(score1, score2));	
				}
			}else if(abs(ctr_b-ctr_g)==1){
				if(strcmp(target1,str)==0){
					printf("0\n");	
				}else{
					printf("%lu\n", transform(target1,str, n, type, arr1, arr2));	
				}
				
			}else{
				printf("-1\n");
			}	
		}else{
			if(abs(ctr_b-ctr_g)>1)
				printf("-1\n");
			else{
				printf("%lu\n",	transform2(str, n, arr1, ctr_g, ctr_b));
			}
			
		}
	}
	return 0;
}