#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<long long> v;
    for(int i = 0; i < a; i++){
        long long x; cin >> x;
        v.push_back(x);
    }
    long long maxans = 0;
    long long minans = LONG_LONG_MAX;
    //cout << minans;
    long long sum = 0;
    for(int i = 1; i < a; i++){
        if(v[i] - v[i-1] < 0){
            //maxans = max(maxans, sum);
            sum = max(sum, maxans - minans);
            minans = LONG_LONG_MAX;
            maxans = 0;
            //sum = 0;
            continue;
        }
        //sum += (v[i] - v[i - 1]);
        maxans = max(maxans, v[i]);
        minans = min(minans, v[i-1]);
        sum = max(sum, maxans - minans);
    }
    cout << sum;
    return 0;
}