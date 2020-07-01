#include <stdio.h>

int n;
int k;
int A[100000];

//pは与えられたmの大きさのバッグで持ち帰るときに必要なバッグの個数がk個以下であるかを判定する
int p(int m){
  int i;
  int t = 0;
  for(i = 0; i < n; i++){
    t = t + (A[i] + m -1) / m;
  }
  return t <= k;
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

