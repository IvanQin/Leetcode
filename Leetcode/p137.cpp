/*int singleNumber(int* nums, int numsSize) {
    int a=0,b=0,t=0;
    for (int i=0;i<numsSize;i++){
        t=a;
        a=(a&(~nums[i]))|(nums[i]&b);
        b=((~nums[i])&b)|(nums[i]&(~t)&(~b));
    }
    return a|b;
}
*/
#include <stdio.h>
#include <stdlib.h>
int a[32]={0}; //wrong initialization!
int singleNumber (int *nums,int numSize){
    int k,j,i,res=0;
	for (i=0;i<32;i++)
		a[i]=0;
    for (int i=0;i<numSize;i++){
        j=nums[i];
        for (k=0;k<32;k++){
            if ((j&(1<<k))!=0)
                a[k]=(a[k]+1)%3;
        }
    }
    for (k=0;k<32;k++)
        if (a[k]==1)
            res=res|(1<<k);
    return res;
}
int main (){
	int *p;
	int *q=(int *)malloc (sizeof(int));
	/*for (int i=0;i<4;i++)
	 	scanf ("%d",&p[i]);*/
    q[0]=3;q[1]=2;q[2]=2;q[3]=2;
	printf ("%d\n",singleNumber(q,4));
	return 0;
}
