#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int adjacency[1001][1001];
int queries[2][100000];

typedef struct node{
	int id;
	struct node *parent;
	struct node *next;
	int rank;
}vertex;

int get_idx(int x,int y,int n,int m){
	if( x>n || y>m)
		return -1;
	else if( x<1 || y<1)
		return -1;
	else
		return ((x-1)*m+y);	
}

void create_graph(int n, int m){
	int i, j, N;
	int cell, right, left, up, down;
	
	N = n*m;
	
	for(i=1;i<=n*m;i++){
		for(j=1;j<=n*m;j++){
			adjacency[i][j] = 0;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cell = get_idx(i,j,n,m);
			right = get_idx(i,j+1,n,m);
			left = get_idx(i,j-1,n,m);
			up = get_idx(i-1,j,n,m);
			down = get_idx(i+1,j,n,m);
			if(right!=-1){
				adjacency[cell][right] = adjacency[right][cell] = 1;
			}
			if(left!=-1){
				adjacency[cell][left] = adjacency[left][cell] = 1;
			}
			if(up!=-1){
				adjacency[cell][up] = adjacency[up][cell] = 1;
			}
			if(down!=-1){
				adjacency[cell][down] = adjacency[down][cell] = 1;
			}
		}
	}
}

void delete_edge(int u, int v, int N){
	if(1<=u && u<=N && 1<=v && v<=N){
		adjacency[u][v] = 0;
	}
}

void create_edge(int u, int v, int N){
	if(1<=u && u<=N && 1<=v && v<=N){
		adjacency[u][v] = 1;
	}
}

int main(){
	
	int t,n,m,q,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &q);
		create_graph(n,m);
		
		
	}
	
	return 0;
}