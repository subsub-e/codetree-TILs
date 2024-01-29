#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int upper(int x){
    int left = 0;
    int right = v.size() - 1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] > x){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int lower(int x){
    int left = 0;
    int right = v.size() - 1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] >= x){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < m; i++){
        int b; cin >> b;
        int ans1 = upper(b);
        int ans2 = lower(b);
        cout << ans1 - ans2 << '\n';
    }
    return 0;
}