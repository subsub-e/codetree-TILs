#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> plus;
    vector<int> minus;
    vector<int> zero;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        if(b > 0){
            cnt1++;
            plus.push_back(b);
        }
        else if(b < 0){
            cnt2++;
            minus.push_back(b);
        }
        else{
            zero.push_back(b);
        }
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    
    int maxans = 0;
    int ans = 1;
    if(cnt1 == 1 || cnt1 >= 3){
        ans = plus[cnt1 - 1] * plus[cnt1 - 2] * plus[cnt1 - 3];
        maxans = max(ans, maxans);
        ans = 1;
        ans = plus[cnt1 - 1] * minus[0] * minus[1];
        maxans = max(ans, maxans);
        cout << maxans;
        ans = 1;
        return 0;
    }
    else{
        if(zero.size() > 0){
            cout << 0;
            return 0;
        }
        else{
            if(cnt1 == 2){
                ans = 1;
                ans = minus[cnt2 - 1] * plus[0] * plus[1];
                maxans = max(ans, maxans);
                cout << maxans;
            }
            ans = 1;
            ans = minus[cnt2 - 1] * minus[cnt2 - 2] * minus[cnt2 - 3];
            maxans = max(ans, maxans);
            cout << maxans;
        }
    }
    return 0;
}