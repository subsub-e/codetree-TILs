#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int> > v;
    for(int i = 0; i < a; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, +1));
        v.push_back(make_pair(y, -1));
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int maxans = 0;
    for(int i = 0; i < 2 * a; i++){
        //cout << v[i].first << ' ' << v[i].second << ' ' << '\n';


        sum += v[i].second;
        maxans = max(maxans, sum);
    }
    cout << maxans;
    return 0;
}