#include <iostream>
using namespace std;
//#define INF -2147483647
int maxProfit(int* prices, int pricesSize) {
	int f[100000][2],i;
	int maxbuy,maxsell,maxn;
	//maxbuy=INF;
	//maxsell=INF;
	for (i=0;i<=pricesSize;i++)
		f[i][0]=f[i][1]=0;
	f[0][0]=0-prices[0];
	maxbuy=f[0][0];
	maxsell=0;
    for (i=1;i<pricesSize;i++){
			f[i][0]=maxsell-prices[i];
			f[i][1]=maxbuy+prices[i];
		if (f[i][0]>maxbuy)
		 	maxbuy=f[i][0];
		if (f[i][1]>maxsell)
			maxsell=f[i][1];
	}
	maxn=0;
	for (i=0;i<pricesSize;i++)
		if (f[i][1]>maxn)
			maxn=f[i][1];      
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