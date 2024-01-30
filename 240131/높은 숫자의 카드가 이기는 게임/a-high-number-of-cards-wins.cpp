#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int cnt = a;
    int ans = 2 * a;
    for(int i = 0; i < a; i++){
        if(v[i] == ans){
            cnt--;
            ans--;
        }
    }
    cout << cnt;
    return 0;
}