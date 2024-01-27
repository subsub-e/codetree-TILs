#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    vector<int> v;
    for(int i = 0; i < a; i++){
        int c; cin >> c;
        v.push_back(c);
    }
    vector<int> sum;
    sum.push_back(0);
    for(int i = 1; i <= a; i++){
        int ans = sum[i-1] + v[i-1];
        sum.push_back(ans);
    }
    // for(int i = 0; i <= a; i++){
    //     cout << sum[i] << ' ';
    // }
    int maxans = 0;
    for(int i = 2; i <= a; i++){
        maxans = max(maxans, sum[i] - sum[i-b]);
    }
    cout << maxans;
    return 0;
}