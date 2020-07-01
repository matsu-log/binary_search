#include <stdio.h>

int n;
int k;
int A[100000];

//pは与えられたmの長さの棒を作った時にk本以上になるか判定する
int p(int m){
  int t = 0;
  int i;
  for(i = 0; i < n; i++){
    t = t + A[i] / m;
  }
  return k <= t;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n" , lb);  
  return 0;
}

