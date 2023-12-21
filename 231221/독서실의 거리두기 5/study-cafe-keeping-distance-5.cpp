#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    string str; cin >> str;
    for(int i = 0; i < a; i++){
        int b = str[i];
        b = b - 48;
        v.push_back(b);
    }
    int max1 = 0;
    int cnt = 0;
    int ans;
    for(int i = 0; i < a; i++){
        if(v[i] == 1){
            cnt = 0;
        }
        else{
            cnt++;
            if(i == a-1){
                if(max1 < cnt){
                    max1 = cnt;
                    ans = i;
                }
                break;
            }
            for(int j = 1; j < cnt; j++){
                if(v[i + j] == 1){
                    cnt = 0;
                    break;
                }
            }
            if(max1 < cnt){
                max1 = cnt;
                ans = i;
            }
        }
    }
    int min = 10000;
    v[ans] = 1;
    int cnt1 = 0;
    for(int i = 0; i < a; i++){
        if(v[i] == 1){
            if(i == 0){
                continue;
            }
            if(min > cnt1){
                min = cnt1;
            }
            cnt1 = 0;
        }
        else{
            cnt1++;
        }
    }
    cout << min + 1;
    return 0;
}