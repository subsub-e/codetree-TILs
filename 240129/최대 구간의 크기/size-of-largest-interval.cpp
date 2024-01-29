#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int> > v;
    for(int i = 0; i < a; i++){
        int x1, x2; cin >> x1 >> x2;
        v.push_back(make_pair(x1, +1));
        v.push_back(make_pair(x2, -1));
    }

    sort(v.begin(), v.end());

    int maxans = 0;
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < a * 2; i++){
        int x, b;
        tie(x, b) = v[i];
        if(cnt > 0){
            int prev;
            tie(prev, ignore) = v[i-1];
            sum += (x - prev);
            maxans = max(maxans, sum);
        }
        else{
            sum = 0;
        }
        cnt += b;
    }
    cout << maxans;
    return 0;
}