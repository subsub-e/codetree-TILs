#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    string str;
    cin >> str;
    int arr[a];
    for(int i = 0; i < a; i++){
        arr[i] = str[i] - 48;
    }
    int max = 0;
    int maxidx;
    int cnt = 0;
    int flag = 0;
    for(int i = 1; i < a; i++){
        if(i == a-1){
            if(arr[i] == 0){
                cnt *= 2;
                if(max < cnt){
                    cnt /= 2;
                    cnt++;
                    flag = 1;
                    maxidx = i;
                    max = cnt;
                    break;
                }
            }
        }
        if(arr[i] == 1){
            if(max < cnt){
                maxidx = i;
                max = cnt;
            }
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    if(flag == 1){
        arr[a-1] = 1;
    }
    else{
        arr[(maxidx+(maxidx - max - 1))/2] = 1;
    }
    // for(int i = 0; i < a; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    int minans = 1000000;
    int cntans = 0;
    for(int i = 1; i < a; i++){
        if(arr[i] == 1){
            if(minans > cntans){
                minans = cntans;
            }
            cntans = 0;
        }
        else{
            cntans++;
        }
    }
    cout << minans + 1;
    return 0;
}