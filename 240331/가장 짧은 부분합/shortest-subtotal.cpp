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
    int en = 0;
    int minans = INT_MAX;
    for(int st = 0; st < n; st++){
        while(sum < m && en < n){
            sum += v[en];
            if(sum >= m){
                minans = min(minans, en - st + 1);
            }
            //cout << st << ' ' << en << ' ' << sum << '\n';
            en++;
        }

        

        sum -= v[st];
    }
    cout << minans;
    return 0;
}