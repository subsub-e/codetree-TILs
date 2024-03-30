#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int sum = 0;
    int en = 0;
    int cnt = 0;
    for(int st = 0; st < n; st++){
        while(en < n && sum + v[en] < m){
            sum += v[en];
            en++;
        }
        if(sum + v[en] == m){
            cnt++;
        }
        sum -= v[st];
    }
    cout << cnt;
    return 0;
}