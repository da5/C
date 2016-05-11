#include<stdio.h>
#define N 100

int **smoke, **color;

void inputCalculate(int n)
{
     int i, j, k, d, min;
     
     for(i=0;i<n;i++)                           //Input
     {
                     scanf("%d", &color[i][i]);
                     smoke[i][i] = 0;
     }
     
     for(d=1; d<=n-1; d++)
     {
              for(i=0;i<=n-d-1;i++)
              {
                                   j = i+d, k = i;     //optimize (i,j) with i <= k < j
                                   min = smoke[i][k] + smoke[k+1][j] + (color[i][k] * color[k+1][j]);
                                   color[i][j] = (color[i][k] + color[k+1][j]) % 100; 
                                   
                                   for(k=i+1;k<j;k++)   
                                         if(min > smoke[i][k] + smoke[k+1][j] + (color[i][k] * color[k+1][j]))
                                         {
                                                min = smoke[i][k] + smoke[k+1][j] + (color[i][k] * color[k+1][j]);  
                                                color[i][j] = (color[i][k] + color[k+1][j]) % 100; 
                                         }   
                                   
                                   smoke[i][j] = min;            
              }
              
     }
     
     printf("%d\n",smoke[0][n-1]);
     
}


main()
{
      int i;
      
      smoke = (int**)malloc(sizeof(int*) * N);
      color = (int**)malloc(sizeof(int*) * N);
      
      for(i=0; i<N; i++)
      {
               *(smoke + i) = (int*)malloc(sizeof(int)*N);
               *(color + i) = (int*)malloc(sizeof(int)*N);
      }
      
      while(scanf("%d",&i)!=EOF)
      {
                                inputCalculate(i);
      }
      
      
      return 0;
}
