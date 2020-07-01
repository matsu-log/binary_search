#include <stdio.h>

int n;
int k;
int A[100000];

//pは与えられたmが最大割り当てである場合、k人以下に割り当てできるか判定する
int p(int m){
  int i,t,l;
  t = 0;
  l = 1;
  for(i=0;i<n;i++){
    t = t + A[i];
    if(t > m) {
      l = l + 1;
      t = A[i];
      if(t > m) return 0; 
    }
  }
  return l <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;

  }
  printf("%d\n" , ub);  
  return 0;
}
