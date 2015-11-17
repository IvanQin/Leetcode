#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f[10000];
int numDecodings(char* s) {
	int i,len;
	char ps;
	
	len=strlen(s);
	if (!len) return 0;
	for (i=0;i<=nlen;i++)
		f[i]=0;
	f[0]=1;
	f[1]=(s[0]!='0')?1:0;
	for (i=2;i<=len;i++){
		ps=s[i-1];
		if (ps=='0') {
			 if (s[i-2]=='1' || s[i-2]=='2')
				f[i]=f[i-2];
			 continue;
			}
		else if ((s[i-2]=='1') || (s[i-2]=='2' && ps<='6')) f[i]=f[i-2];
		f[i]+=f[i-1];
	}
	return f[len];
}
int main (){
	char *s;
	scanf ("%s",s);
	printf ("%d\n",numDecodings(s));
	return 0;
}