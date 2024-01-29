#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int a;
int b, c;
vector<long long> v;

int func(int x){
    int left = 0;
    int right = v.size() - 1;
    int cnt = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == x){
            break;
        }
        else if(v[mid] > x){
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
    cin >> a;
    cin >> b >> c;
    for(int i = 1; i <= a; i++){
        v.push_back(i);
    }
    int minans = INT_MAX;
    int maxans = 0;
    for(int i = b; i <= c; i++){
        int ans = func(i);
        //cout << ans << ' ';
        minans = min(minans, ans);
        maxans = max(maxans, ans);
    }
    //cout << '\n';
    cout << minans << ' ' << maxans;
    return 0;
}