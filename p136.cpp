#include <stdio.h>
#include <stdlib.h>
int singleNumber(int* nums, int numsSize) {
    int singleNumber(int* nums, int numsSize) {
    int res=0;
    for (int i=0;i<numsSize;i++)   
        res=res^nums[i];
    return res;
}
int main (){
	int *p=(int *)malloc(sizeof(int)*10);
	for (int i=0;i<10;i++)
		scanf ("%d",&p[i]);	
	printf (singleNumber(p,10));
}