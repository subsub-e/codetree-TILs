#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

long long a;
long long b, c;
vector<long long> v;

int func(int x){
    long long left = 1;
    long long right = a;
    long long cnt = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(mid == x){
            break;
        }
        else if(mid > x){
            right = mid - 1;
            cnt++;
        }
        else{
            left = mid + 1;
            cnt++;
        }
    }
    return cnt + 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b >> c;
    // for(int i = 1; i <= a; i++){
    //     v.push_back(i);
    // }
    long long minans = INT_MAX;
    long long maxans = 0;
    for(int i = b; i <= c; i++){
        long long ans = func(i);
        //cout << ans << ' ';
        minans = min(minans, ans);
        maxans = max(maxans, ans);
    }
    //cout << '\n';
    cout << minans << ' ' << maxans;
    return 0;
}