#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int upper(int x){
    int left = 0;
    int right = v.size() - 1;
    int minidx = n + 2;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] > x){
            right = mid - 1;
            minidx = min(minidx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return minidx;
}

int lower(int x){
    int left = 0;
    int right = v.size() - 1;
    int minidx = n + 2;
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
    return minidx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    v.push_back(0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    v.push_back(1000000001);
    for(int i = 0; i < m; i++){
        int x1, x2; cin >> x1 >> x2;
        int ans1 = upper(x2);
        int ans2 = lower(x1);
        //cout << ans1 << ' ' << ans2 << '\n';
        cout << ans1 - ans2 << '\n';
    }
    return 0;
}