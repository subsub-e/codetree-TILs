#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int> > v;
    for(int i = 0; i < a; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, +1));
        v.push_back(make_pair(x2, -1));
    }

    int cnt = 0;
    int maxans = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < a * 2; i++){
        cnt += v[i].second;
        maxans = max(maxans, cnt);
    }
    cout << maxans;
    return 0;
}