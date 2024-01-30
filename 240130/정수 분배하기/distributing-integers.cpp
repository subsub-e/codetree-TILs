#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
vector<int> v;

int func(int x){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += (v[i]) / x;
    }
    //cout << cnt << ' ' << x << '\n';
    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    int right = INT_MAX;
    int left = 1;
    int maxans = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
        right = min(right, a);
    }
    int mid = right - 1;
    while(left <= right){
        if(func(mid) >= k){
            left = mid + 1;
            maxans = max(maxans, mid);
        }
        else{
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    cout << maxans;
    return 0;
}