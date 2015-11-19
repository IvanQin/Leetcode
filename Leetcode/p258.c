#include <stdio.h>
int deal (int i){
  int s=0,res;
  if (!(i/10)) return i;
  while(i){
    s+=i%10;
    i/=10;
  }
  res=deal(s);
  return res;
}
int main (){

  int i;
  for (i=1;i<=1000;i++)
    printf ("num=%d sum=%d\n",i,deal(i));
  return 0;
}
