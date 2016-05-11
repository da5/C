#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )

int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l+1; j = r;
        
   while( 1)
   {
    while( a[i] <= pivot && i <= r )
        i++;
    while( a[j] > pivot && j>=l+1)
        j--;
    if( i >= j ) break;
    t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
    // divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
    
}
int isSumPossible(int a[], int L, int N ){
/*L: Length of the array */
    if(L==1)
        return 0;
    quickSort(a,0,L-1);
    
    for(int i=0;i<L;i++)
      printf("%d ", a[i]);
    printf("\n");

    int i = 0, j=L-1;
    while(i<j)
    {
        if(a[i]+a[j]==N)
            return 1;
        else if(a[i]+a[j]>N)
            j--;
        else
            i++;
    }
    return 0;
}

int main(){
    int N; scanf("%d",&N);
    int a[100004],i = 0;    
    
    for( i = 0;i < N;i++ ){
        scanf("%d",&a[i]);  
    }
    int x; scanf("%d",&x);  
    printf("%d\n",isSumPossible(a,N,x));
    
return 0;
}