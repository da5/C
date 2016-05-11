#include<stdio.h>

int main(){
	unsigned long int t,n1,n2,m;
	scanf("%lu",&t);
	while(t--){
		scanf("%lu%lu%lu",&n1,&n2,&m);
		while(n1>0 && n2>0 && m>0){
			if(n1>=m && n2>=m){
				n1-=m;
				n2-=m;	
			}
			m--;
			if(n1<m && n2<m){
				m = (n1<n2)?n1:n2;
			}
			else if(n1<m){
				m = n1;
			}else if(n2<m){
				m = n2;
			}
		}
		m = n1+n2;
		printf("%lu\n",m);
	}
	return 0; 
}
