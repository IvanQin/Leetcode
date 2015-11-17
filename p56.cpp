#include <stdio.h>
#include <stdlib.h>
#define N 100
 struct Interval {
      int start;
      int end;
  };
 
int cmp (const void *a,const void *b){
	struct Interval *aa=(struct Interval*)a;
	struct Interval *bb=(struct Interval*)b;
	if (aa->start!=bb->start)
		return ((aa->start)-(bb->start)>0)?1:-1;
	return ((aa->end)-(bb->end)>0)?1:-1;
}
int num;
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
	struct Interval *res=(struct Interval *)malloc (sizeof(struct Interval)*N);
	int i=0,start,end,mend;
	num=0;
    qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);
	/*for (i=0;i<intervalsSize;i++)
		printf ("start=%d end=%d\n",intervals[i].start,intervals[i].end);
	printf ("\n");*/
	i=0;
	while (i<intervalsSize){
		start=intervals[i].start;
		mend=intervals[i].end;
		while (i<intervalsSize-1 && mend>=intervals[i+1].start) {
			if (intervals[i+1].end>mend)
				mend=intervals[i+1].end;
			i++;
		}
			
		end =mend;
		struct Interval p;
		p.start=start;
		p.end=end;
		res[num++]=p;
		i++;
		//printf ("start=%d end=%d\n",p.start,p.end);
	}
	*returnSize=num;
	return res;
}
	
/*void quicksort(int *a,int left,int right){
	int i,last;
	if (left>=right) return;
	mid=(left+right)/2;
	last=i;
	swap (mid,right);
	for (i=last;i<right;i++)
		if (a[i]<last) swap(++last,i);
	swap 
	quicksort()
}*/

int main (){
	int n,i,*returnSize;
	struct Interval *a=(struct Interval*)malloc(sizeof(Interval)*N);
	returnSize=(int *)malloc(sizeof(int));
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf ("%d%d",&a[i].start,&a[i].end);
	a=merge(a,n,returnSize);
	for (i=0;i<num;i++)
		printf ("start=%d end=%d\n",a[i].start,a[i].end);
	return 0;
}