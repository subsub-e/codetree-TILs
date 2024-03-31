#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int minans = INT_MAX;
    int st = 0;
    int en = n - 1;
    while(st < en){
        int temp = v[st] + v[en];
        minans = min(minans, abs(temp));
        if(temp > 0){
            en--;
        }
        else{
            st++;
        }
    }
    cout << minans;
    return 0;
}