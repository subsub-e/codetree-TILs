#include <stdio.h>
#include <vector>
#include <climits>
using namespace std;
int n,m;
int ans=INT_MIN;
int num[20];
vector<int> number;


int max(int a,int b){
  if(a>b) return a;
  return b;
}


void choose(int cnt, int st_idx) {
  if(cnt==m) {
    int x=number[0];
    for(int i=1;i<number.size();i++) x^=number[i];
    ans=max(ans,x);
    return;
  }
  for(int i=st_idx;i<=n;i++) {
    number.push_back(num[i]);
    choose(cnt+1,st_idx+1);
    number.pop_back();
  }
}
int main() {
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++) scanf("%d",&num[i]);
  choose(0, 0);
  printf("%d",ans);
  return 0;
}