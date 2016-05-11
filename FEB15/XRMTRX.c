#include<stdio.h>

int getscore(char c){
	if(c=='Q' || c=='q')
		return 9;
	else if(c=='R' || c=='r')
		return 5;
	else if(c=='B' || c=='b')
		return 3;
	else if(c=='N' || c=='n')
		return 3;
	else if(c=='P' || c=='p')
		return 1;
	else if(c=='K' || c=='k')
		return 0;
	else
		return 0;
}

int main()
{
	int i,j,black_score = 0, white_score = 0;
	char str[10];
	for(i=0;i<8;i++){
		scanf("%s",str);
		for(j=0;j<8;j++){
			if(str[j]>='a' && str[j]<='z'){
				black_score += getscore(str[j]);
			}else if(str[j]>='A' && str[j]<='Z'){
				white_score += getscore(str[j]);
			}
		}
	}
	if(white_score > black_score){
		printf("White\n");
	}else if(white_score < black_score){
		printf("Black\n");
	}else{
		printf("Draw\n");
	}
	return 0;
}
