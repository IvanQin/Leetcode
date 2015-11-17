#include <iostream>
using namespace std;
#define INF -2147483647
int f[100000][4];
int max (int a,int b){
	return a>b?a:b;
}
int maxProfit(int* prices, int pricesSize) {
	int i;
	int maxbuy1,maxbuy2,maxsell1,maxsell0,maxn;
	//maxbuy=INF;
	//maxsell=INF;
	for (i=0;i<=pricesSize;i++){
		f[i][0]=f[i][1]=0;
		f[i][3]=INF;
		f[i][2]=INF;
	}
	f[0][0]=0-prices[0];
	maxbuy1=f[0][0];
	maxsell0=0;
	maxbuy2=INF;
	maxsell1=INF;
    for (i=1;i<pricesSize;i++){
		f[i][0]=maxsell0-prices[i];
		if(maxsell1!=INF){
			f[i][1]=max(maxbuy1,maxsell1)+prices[i];
			f[i][2]=max(maxbuy1,maxsell1)-prices[i];
		}
		else {
			f[i][1]=maxbuy1+prices[i];
			f[i][2]=maxbuy1-prices[i];
		}
		if (maxbuy2!=INF)
			f[i][3]=maxbuy2+prices[i];
		if (f[i][0]>maxbuy1)
		 	maxbuy1=f[i][0];
		if (f[i][1]>maxsell0)
			maxsell0=f[i][1];
		if (f[i][2]>maxbuy2)
			maxbuy2=f[i][2];
		if (f[i][3]>maxsell1)
			maxsell1=f[i][3];
	}
	maxn=0;
	for (i=0;i<pricesSize;i++)
		if (f[i][1]>maxn)
			maxn=f[i][1];      
    return maxn;
}
int main (){
	int *prices=new (int),i,n,j;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> prices[i];
	
	cout << endl << maxProfit(prices,n) << endl;
	
	for (i=0;i<n;i++){
		for (j=0;j<4;j++)
			cout << f[i][j] << ' ';
		cout << endl;
	}
	return 0;
}