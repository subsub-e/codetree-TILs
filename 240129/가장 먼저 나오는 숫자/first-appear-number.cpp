#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; 
vector<int> v;

int lower(int x){
    int left = 0;
    int right = v.size();
    int minidx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] >= x){
            right = mid - 1;
            minidx = min(minidx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    if(v[minidx] == x){
        return minidx + 1;
    }
    return -1;
    //return minidx + 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for(int j = 0; j < m; j++){
        int b; cin >> b;
        int ans = lower(b);
        cout << ans << '\n';
    }
    return 0;
}