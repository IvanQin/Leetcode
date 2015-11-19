#include <iostream>
using namespace std;
int maxProfit(int* prices, int pricesSize) {
	int i,maxn;
	int b[10000],f[10000];
	for (i=0;i<=pricesSize;i++)
		b[i]=f[i]=0;
	for (i=1;i<pricesSize;i++)
		b[i]=prices[i]-prices[i-1];
	f[0]=0;
	for (i=1;i<pricesSize;i++)
			if (b[i]>0)
				f[i]=max(f[i-1]+b[i],b[i]);
			else f[i]=max(f[i-1]+b[i],0);
	maxn=0;
	for (i=0;i<pricesSize;i++)
		if (maxn<f[i])
			maxn=f[i];
    return maxn;
}
int main (){
	int *prices=new (int),i,n;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> prices[i];
	cout << endl << maxProfit(prices,n) << endl;
	return 0;
}