#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int a;
int arr[20];
vector<int> v;
int ans = INT_MAX;

int calc(){
  int cnt1 = 0;
  int cnt2 = 0;
  cnt1 += arr[0];
  int j = 0;
  for(int i = 1; i < a * 2; i++){
    if(i == v[j]){
      cnt1 += arr[i];
      j++;
    }
    else{
      cnt2 += arr[i];
    }
  }
  return abs(cnt1 - cnt2);
}

void simulate(int x, int count){
    if(count == a){
        ans = min(ans, calc());
        //cout << ans << '\n';
        return;
    }

    for(int i = x; i < a * 2; i++){
        v.push_back(i);
        // for(int i = 0; i < v.size(); i++){
        //   cout << v[i] << ' ';
        // }
        // cout << '\n';
        simulate(i + 1, count + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a * 2; i++){
        cin >> arr[i];
    }
    if(a == 1){
      cout << arr[1] - arr[0];
      return 0;
    }
    simulate(1, 1);
    cout << ans;
    return 0;
}