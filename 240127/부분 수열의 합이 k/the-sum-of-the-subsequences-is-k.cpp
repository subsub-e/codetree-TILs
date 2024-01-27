#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k; cin >> n >> k;
    vector<int> v;
    vector<int> sum;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sum.push_back(0);
    for(int i = 1; i <= n; i++){
        sum.push_back(v[i-1] + sum[i-1]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(k == sum[i] - sum[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}