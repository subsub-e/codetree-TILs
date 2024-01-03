#include <iostream>
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
        for(int i=1;i<number.size();i++){
            //cout << x << ' ';
            x^=number[i];
        } 
        //cout << '\n';
        ans=max(ans,x);
        return;
    }
    
    for(int i=st_idx;i<n;i++) {
        number.push_back(num[i]);
        // for(int i = 0; i < number.size(); i++){
        //     cout << number[i] << ' ';
        // }
        // cout << '\n';
        choose(cnt+1,i + 1);
        number.pop_back();
    }
}

int main() {
  cin >> n >> m;
  for(int i= 0; i < n; i++){
    cin >> num[i];
  }
  choose(0, 0);
  cout << ans;
  return 0;
}