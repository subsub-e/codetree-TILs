#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long n; cin >> n;
    long long left = 1;
    long long right = INT_MAX;
    long long maxans = -1;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(mid * (mid + 1) / 2 > n){
            right = mid - 1;
        }
        else{
            left = mid + 1;
            maxans = max(maxans, mid);
        }
    }
    cout << maxans;
    return 0;
}