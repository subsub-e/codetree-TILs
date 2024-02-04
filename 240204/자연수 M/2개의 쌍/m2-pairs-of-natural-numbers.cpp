#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        for(int i = 0; i < a; i++){
            v.push_back(b);
        }
    }
    sort(v.begin(), v.end());
    int maxans = 0;
    for(int i = 0; i < v.size() / 2; i++){
        int ans = v[i] + v[v.size() - i - 1];
        maxans = max(maxans, ans);
    }
    cout << maxans;
    return 0;
}