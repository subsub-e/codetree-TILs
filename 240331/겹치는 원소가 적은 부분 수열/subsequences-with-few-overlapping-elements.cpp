#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int maxans = 0;
    int st = 0;
    int en = 0;

    while(st < n){
        while(en < n && m[v[en]] + 1 <= k){
            m[v[en]]++;
            maxans = max(maxans, en - st + 1);
            en++;
        }

        m[v[st]]--;
        st++;
    }

    cout << maxans;
    
    return 0;
}