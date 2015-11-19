#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
int p[N][N];
/*void DFS(char *s,char *t,int p,int pi){
    if (t[p]=='\0') num++;
    else {
        for (int i=pi+1;s[i]!='\0';i++){
            if (s[i]==t[p])
                DFS(s,t,p+1,i);
        }
    }
}
int main (){
    char *s,*t;
    num=0;
    s=(char *)malloc(sizeof(char)*N);
    t=(char *)malloc(sizeof(char)*N);
    scanf ("%s",s);
    scanf ("%s",t);
    if (s==NULL) num=0;
    else DFS(s,t,0,-1);
    
    printf ("%d\n",num);
    }
*/
void work (int ls,int lt,char *s,char *t){
    int i,j;
    for (i=0;i<=1;i++)
        for (j=0;j<ls;j++)
            p[i][j]=0;
    for (i=ls;i>=0;i--)
        p[i][lt]=1;
   for (j=lt-1;j>=0;j--){
      for (i=ls-(lt-j);i>=0;i--)
            if (s[i]==t[j])
                p[i][j]=p[(i+1)][j+1]+p[(i+1)][j];
            else p[i][j]=p[(i+1)][j];
    }
}
int main (){
    char *s,*t;
    int ls,lt,i,j;
    s=(char *)malloc(sizeof(char)*N);
    t=(char *)malloc(sizeof(char)*N);
    scanf ("%s",s);
    scanf ("%s",t);
    ls=strlen(s);
    lt=strlen(t);
    if (s==NULL) p[0][0]=0;
    else work(ls,lt,s,t);

    printf ("%d\n",p[0][0]);
}
