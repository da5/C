#include<stdio.h>
#include<string.h>
int main()
{
	int tc, ctr[26],i,j,t,l;
	int subset[51][27];
	char str[50];
	scanf("%d", &tc);
	while(tc--)
	{
		
		scanf("%s",str);
		l = strlen(str);
		if(l%2==1){
			printf("NO\n");
		}else{
			for(i=0;i<26;i++)
				ctr[i] = 0;
			for(i=0;i<l;i++)
				ctr[str[i]-'a']++;
			// for(i=0;i<25;i++){
			// 	for(j=i+1;j<26;j++)
			// 		if(ctr[i]>ctr[j]){
			// 			t = ctr[i];
			// 			ctr[i] = ctr[j];
			// 			ctr[j] = t;
			// 		}
			// }
		
			// i=0,j=25;
			// while(i<j){
			// 	if(ctr[i]+ctr[j]==l/2)
			// 		break;
			// 	else if(ctr[i]+ctr[j]<l/2)
			// 		i++;
			// 	else
			// 		j--;
			// }
				
			// if(i>=j)
			// 	printf("NO\n");
			// else
			// 	printf("YES\n");
			for (i = 0; i <= 26; i++)
      			subset[0][i] = 1;	
      		for (i = 1; i <= l/2; i++)
      			subset[i][0] = 0;

      		for (i = 1; i <= l/2; i++)
		    {
		       for (j = 1; j <= 26; j++)
		       {
		         subset[i][j] = subset[i][j-1];
		         if (i >= ctr[j-1]){
		         	// subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
		         	if(subset[i][j]==1 || subset[i - ctr[j-1]][j-1]==1)
		         		subset[i][j] = 1;
		         }
		           
		       }
		    }
		    if(subset[l/2][26]==0)
				printf("NO\n");
			else
				printf("YES\n");
		}

		

			
	}
	return 0;
}

