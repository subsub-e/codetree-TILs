#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    long long m;
    vector<int> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    long long sum = 0;
    int st = 0;
    int minans = INT_MAX;

    for(int en = 0; en < n; en++){
        while(sum >= m && st <= en){
            
            minans = min(minans, en - st);
            sum -= v[st];
            st++;
        }

        sum += v[en];

    }
    if(minans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << minans;
    return 0;
}