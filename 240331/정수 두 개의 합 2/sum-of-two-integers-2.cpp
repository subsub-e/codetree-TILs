#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int sum = v[0];
    int cnt = 0;
    int en = n - 1;
    for(int st = 0; st < n - 1; st++){
        while(en > 0 && v[st] + v[en] > m){
            en--;
        }
        if(en <= st){
            break;
        }
        cnt += en - st;
    }
    cout << cnt;
    return 0;
}