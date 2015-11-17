#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int s_length;
bool flag;
int isString (int p,int i,char *s,char **wordDict){
	char *sub=(char *)malloc(sizeof(char)*N);
	strcpy(sub,wordDict[i]);
	int k=0;
	while (sub[k]!='\0'){
		if (s[p]=='\0'){
			if (sub[k]=='\0')
				return p;
			else return -1;
			}
		if (s[p++]!=sub[k++])
			return -1;
	}
	return p; 
}
void DFS(int p,char *s,char **wordDict,int n){
	int i,q;
	if (flag==true) return;
	if (p==s_length){
		flag=true;
		return;
		}
	else for (i=0;i<n;i++){
			q=isString(p,i,s,wordDict);
			if (q!=-1)
				DFS(q,s,wordDict,n);
	}
}
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
	flag=false;
	s_length=strlen(s);
	DFS(0,s,wordDict,wordDictSize);
    return flag;
}
int main (){
	int i,n;
	char *s=(char *)malloc (sizeof(char)*N);
	char **wordDict=(char **)malloc (sizeof(char *)*N);//must be malloced!!
	scanf ("%s",s);
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		char *tmp=(char *)malloc (sizeof(char)*N);
		scanf ("%s",tmp);
		wordDict[i]=tmp;
	}
	printf ("%d\n",wordBreak(s,wordDict,n));
	
	return 0;
}