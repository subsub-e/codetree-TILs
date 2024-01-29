#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

long long a;
long long b, c;
vector<long long> v;

int func(long long x){
    long long left = 1;
    long long right = a;
    int cnt = 0;
    while(left <= right){
        cnt++;
        long long mid = (left + right) / 2;
        if(mid == x){
            return cnt;
        }
        else if(mid > x){
            right = mid - 1;
            //cnt++;
        }
        else{
            left = mid + 1;
            //cnt++;
        }
    }
    return -1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b >> c;
    // for(int i = 1; i <= a; i++){
    //     v.push_back(i);
    // }
    int minans = INT_MAX;
    int maxans = 0;
    for(long long i = b; i <= c; i++){
        int ans = func(i);
        //cout << ans << ' ';
        minans = min(minans, ans);
        maxans = max(maxans, ans);
    }
    //cout << '\n';
    cout << minans << ' ' << maxans;
    return 0;
}