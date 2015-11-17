#include <stdio.h>
int lhigh[100000],rhigh[100000];
int min (int a,int b){
	return a<b?a:b;
}
int trap(int* height, int heightSize) {
	int i=0,sum=0,high,h;
	for (i=0;i<=heightSize;i++)
		lhigh[i]=rhigh[i]=0;
	high=height[0];
	for (i=1;i<heightSize;i++){
		lhigh[i]=high;
		if (high<height[i])
			 high=height[i];
		}
	high=height[heightSize-1];
	for (i=heightSize-2;i>=0;i--){
		rhigh[i]=high;
		if (high<height[i])
			 high=height[i];
	}
	for (i=0;i<heightSize;i++){
		h=min(rhigh[i],lhigh[i]);
		sum+=(h-height[i]>0)?h-height[i]:0;
	}
	return sum;		
}
int a[100];
int main (){
	int n,i;
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf ("%d",&a[i]);
	printf ("%d\n",trap(a,n));
	return 0;
}