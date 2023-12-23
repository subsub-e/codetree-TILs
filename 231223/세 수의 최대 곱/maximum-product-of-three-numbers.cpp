#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    int maxans = INT_MIN;
    int cnt1 = v[v.size() - 1] * v[v.size() - 2] * v[v.size() - 3];
    maxans = max(maxans, cnt1);
    int cnt2 = v[v.size() - 1] * v[0] * v[1];
    maxans = max(maxans, cnt2);
    cout << maxans;
    return 0;
}