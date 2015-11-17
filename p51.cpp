#include <stdio.h>
#include <stdlib.h>
#define N 100
int solution;
char ***tmp;
bool col[100],mdia[100],sdia[100];

char ** create(int res[],int n){
	int i,j;
	char **bs=(char **)malloc (sizeof(char *)*N);
	for (i=0;i<n;i++){
		char *s=(char *)malloc (sizeof(char)*N);
		for (j=0;j<n;j++)
			s[j]='.';
		s[res[i]]='Q';
		bs[i]=s;
	}
	return bs;
}
void DFS(int n,int layer,int res[]){
	int i;
	if (layer>=n){
		tmp[solution]=create(res,n);
		solution++;
		return;
	}
	else for (i=0;i<n;i++){
			if (!col[i] && !sdia[i+layer+n] && !mdia[i-layer+n]){
				col[i]=true;
				sdia[i+layer+n]=true;
				mdia[i-layer+n]=true;
				res[layer]=i;
				DFS(n,layer+1,res);
				res[layer]=-1;
				col[i]=false;
				sdia[i+layer+n]=false;
				mdia[i-layer+n]=false;
			}
				
		
	}
}
char*** solveNQueens(int n, int* returnSize) {
	int res[100],i;
	*returnSize=0;
	if (!n) return NULL;
	//printf ("OK");
	tmp=(char ***)malloc (sizeof(char ***)*10000);
	solution=0;
	for (i=0;i<100;i++)
		col[i]=mdia[i]=sdia[i]=false;
	//printf ("OK");
    DFS(n,0,res);
	*returnSize=solution;
	//printf ("returnSize=%d\n",*returnSize);
	return tmp;
}


int main (){
	int n,i,j;
	char ***queen=(char ***)malloc (sizeof(char ***)*10000);
	int *sol=(int *)malloc (sizeof(int));
	scanf ("%d",&n);
	//printf ("OK");
	queen=solveNQueens(n,sol);
	//printf ("sol=%d\n",*sol);
	for (i=0;i<*sol;i++){
		for (j=0;j<n;j++)
			printf ("%s\n",queen[i][j]);
		printf ("\n");
	}
	return 0;
}