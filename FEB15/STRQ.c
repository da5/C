#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_idx(char c){
	if(c=='c')
		return 0;
	else if(c=='h')
		return 1;
	else if(c=='e')
		return 2;
	else if(c=='f')
		return 3;
	return -1;
}

int get_double_idx(char a, char b){
	if(a=='c'){
		if(b=='h')
			return 0;
		else if(b=='e')
			return 1;
		else if(b=='f')
			return 2;		
	}else if(a=='h'){
		if(b=='c')
			return 3;
		else if(b=='e')
			return 4;
		else if(b=='f')
			return 5;
	}else if(a=='e'){
		if(b=='c')
			return 6;
		else if(b=='h')
			return 7;
		else if(b=='f')
			return 8;		
	}else if(a=='f'){
		if(b=='c')
			return 9;
		else if(b=='h')
			return 10;
		else if(b=='e')
			return 11;		
	}
	return -1;
}

int main()
{
	int i,j,len,q,l,r,ctr,idx;
	char a[2],b[2]; 
	char *str = (char*)malloc(sizeof(char)*1000000);

	int **freq = (int**)malloc(sizeof(int*)*4);
	for(i= 0;i<4;i++)
		freq[i] = (int*)malloc(sizeof(int)*1000000);	

	int **words = (int**)malloc(sizeof(int*)*12);
	for(i=0;i<12;i++)
		words[i] = (int*)malloc(sizeof(int)*1000000);

	scanf("%s", str);
	len = strlen(str);

	for(i= 0;i<4;i++)
		freq[i][0] = 0;	
	freq[get_idx(str[0])][0] = 1;

	for(i=1;i<len;i++){
		for(j= 0;j<4;j++){
			freq[j][i] = freq[j][i-1];			
		}
		freq[get_idx(str[i])][i]++;
	}


	for(i= 0;i<12;i++)
		words[i][0] = 0;
	for(i=1;i<len;i++){
		for(j= 0;j<12;j++){
			words[j][i] = words[j][i-1];
		}
		
		idx = get_double_idx('c',str[i]);
		if(idx!=-1){
			words[idx][i] += freq[get_idx('c')][i-1];	
		}
		idx = get_double_idx('h',str[i]);
		if(idx!=-1){
			words[idx][i] += freq[get_idx('h')][i-1];	
		}
		idx = get_double_idx('e',str[i]);
		if(idx!=-1){
			words[idx][i] += freq[get_idx('e')][i-1];	
		}
		idx = get_double_idx('f',str[i]);
		if(idx!=-1){
			words[idx][i] += freq[get_idx('f')][i-1];	
		}
	}

	// printf("c - f\n");
	// for(i=0;i<len;i++){
	// 	printf("%d ", words[get_double_idx('c','f')][i]);
	// }
	// printf("\nc - f\n");

	// printf("c - h\n");
	// for(i=0;i<len;i++){
	// 	printf("%d ", words[get_double_idx('c','h')][i]);
	// }
	// printf("\nc - h\n");
	
	scanf("%d",&q);
	while(q--){
		scanf("%s%s%d%d",a,b,&l,&r);
		
//		printf("%d - %d - (%d * (%d - %d)) = ", words[get_double_idx(a[0],b[0])][r-1],words[get_double_idx(a[0],b[0])][l-2],freq[get_idx(a[0])][l-2],freq[get_idx(b[0])][r-1],freq[get_idx(b[0])][l-2]);
		if(l==1){
			ctr = words[get_double_idx(a[0],b[0])][r-1];
		}else{
			ctr = words[get_double_idx(a[0],b[0])][r-1] 
		      - words[get_double_idx(a[0],b[0])][l-2] 
		      - (freq[get_idx(a[0])][l-2]*
		      	(freq[get_idx(b[0])][r-1]-freq[get_idx(b[0])][l-2]));

		}
		
		printf("%d\n",ctr);
	}

	return 0;
}
