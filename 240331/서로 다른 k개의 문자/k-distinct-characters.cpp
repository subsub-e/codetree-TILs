#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str; cin >> str;
    int n = str.length();
    int m; cin >> m;
    int maxans = 0;
    int st = 0;
    int en = 0;
    int arr[26] = {};
    int cnt = 0;
    int temp[26] = {};
    while(st < n){
        while(en < n && cnt + abs(arr[(int)str[en] - 97] -1) <= m){
            if(arr[(int)str[en] - 97] == 0){
                cnt++;
                
            }
            arr[(int)str[en] - 97] = 1;
            temp[(int)str[en] - 97]++;
            maxans = max(maxans, en - st + 1);
            //cout << st << ' ' << en << ' ' << maxans << '\n';
            en++;
        }
        temp[(int)str[st] - 97]--;
        if(temp[(int)str[st] - 97] == 0){
            cnt--;
            arr[(int)str[st] - 97] = 0;
        }
        st++;
    }
    cout << maxans;
    return 0;
}