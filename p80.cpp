#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	int res=numsSize;
	int p,q,i;
	if (numsSize<3) return numsSize;
	p=nums[0];q=nums[1];
	i=2;
	while (i<numsSize){
		if (p==q && nums[i]==p) res--;
		p=q;
		q=nums[i];
		
		i++;
		//printf ("res=%d p=%d q=%d\n",res,p,q);
	}
    return res;
}
int main (){
	int n,a[100];
	scanf ("%d",&n);
	for (int i=0;i<n;i++)
		scanf ("%d",&a[i]);
	printf ("%d\n",removeDuplicates(a,n));
}